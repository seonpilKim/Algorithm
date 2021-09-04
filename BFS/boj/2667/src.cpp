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

	int n;
	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> ans;
	queue<pair<int, int>> q;
	vector<vector<bool>> isVisited(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '1' && !isVisited[i][j]) {
				int cnt = 0;
				q.emplace(i, j);
				isVisited[i][j] = true;
				while (!q.empty()) {
					int row = q.front().first;
					int col = q.front().second;
					q.pop();
					cnt++;

					for (int d = 0; d < 4; d++) {
						int nextRow = row + dr[d];
						int nextCol = col + dc[d];

						if (nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= n)
							continue;
						if (v[nextRow][nextCol] == '0')
							continue;
						if (isVisited[nextRow][nextCol])
							continue;

						isVisited[nextRow][nextCol] = true;
						q.emplace(nextRow, nextCol);
					}
				}
				ans.push_back(cnt);
			}
		}
	}
	
	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int a : ans)
		cout << a << '\n';
	
	return 0;
}