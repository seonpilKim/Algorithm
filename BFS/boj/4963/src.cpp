#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <math.h>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <bitset>

using namespace std;

#define NONE -1
#define MAX 1e3 + 1
#define MOD (int)(1e4 + 7);

const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dc[] = {-1, 0, 1, 0, -1, 1, -1, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		int r, c;
		cin >> c >> r;
		if (r == 0 && c == 0)
			break;

		vector<vector<int>> m(r, vector<int>(c));
		vector<vector<bool>> isVisited(r, vector<bool>(c));
		queue<pair<int, int>> q;
		int ans = 0;

		for (int i = 0; i < r; i++) 
			for (int j = 0; j < c; j++) 
				cin >> m[i][j];

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (m[i][j] == 0 || isVisited[i][j])
					continue;
				
				ans++;
				q.emplace(i, j);
				isVisited[i][j] = true;

				while (!q.empty()) {
					int row = q.front().first;
					int col = q.front().second;
					q.pop();

					for (int i = 0; i < 8; i++) {
						int nextRow = row + dr[i];
						int nextCol = col + dc[i];

						if (nextRow < 0 || nextCol < 0 || nextRow >= r || nextCol >= c)
							continue;
						if (isVisited[nextRow][nextCol])
							continue;
						if (m[nextRow][nextCol] == 0)
							continue;

						isVisited[nextRow][nextCol] = true;
						q.emplace(nextRow, nextCol);
					}
				}
			}
		}

		cout << ans << '\n';
	}
	
	return 0;
}