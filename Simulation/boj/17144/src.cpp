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
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C, T;
	cin >> R >> C >> T;
	vector<vector<int>> air(R, vector<int>(C));
	vector<int> airCleaner;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> air[i][j];
			if (air[i][j] == -1)
				airCleaner.push_back(i);
		}
	}

	for (int i = 0; i < T; i++) {
		queue<pair<int, int>> dust;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (air[i][j] > 4)
					dust.emplace(i, j);
			}
		}
		int size = dust.size();

		vector<int> amount;
		int dr[] = {1, -1, 0, 0};
		int dc[] = {0, 0, 1, -1};
		for (int i = 0; i < size; i++) {
			int row = dust.front().first;
			int col = dust.front().second;
			dust.push(dust.front());
			dust.pop();
			amount.push_back(air[row][col]);
		}

		for (int i = 0; i < size; i++) {
			int row = dust.front().first;
			int col = dust.front().second;
			dust.pop();

			int cnt = 0;
			int spread = amount[i] / 5;
			for (int i = 0; i < 4; i++) {
				int newRow = row + dr[i];
				int newCol = col + dc[i];
				if (newRow < 0 || newRow >= R || newCol < 0 || newCol >= C)
					continue;
				if (air[newRow][newCol] == -1)
					continue;

				cnt++;
				air[newRow][newCol] += spread;
			}
			air[row][col] -= cnt * spread;
		}

		for (int row = airCleaner[0] - 1; row > 0; row--)
			air[row][0] = air[row - 1][0];
		for (int row = airCleaner[1] + 1; row < R - 1; row++)
			air[row][0] = air[row + 1][0];

		for (int col = 0; col < C - 1; col++) {
			air[0][col] = air[0][col + 1];
			air[R - 1][col] = air[R - 1][col + 1];
		}

		for (int row = 0; row < airCleaner[0]; row++)
			air[row][C - 1] = air[row + 1][C - 1];
		for (int row = R - 1; row > airCleaner[1]; row--)
			air[row][C - 1] = air[row - 1][C - 1];

		for (int col = C - 1; col > 1; col--) {
			air[airCleaner[0]][col] = air[airCleaner[0]][col - 1];
			air[airCleaner[1]][col] = air[airCleaner[1]][col - 1];
		}
		air[airCleaner[0]][1] = 0;
		air[airCleaner[1]][1] = 0;
	}

	int ans = 2;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ans += air[i][j];
	cout << ans;

	return 0;
}
