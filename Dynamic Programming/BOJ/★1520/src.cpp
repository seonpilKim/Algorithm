#include <iostream>
#include <vector>

#define UNVISITED -1

using namespace std;

int r, c;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
vector<vector<int>> map;
vector<vector<int>> dp;

int DFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;
	map.assign(r, vector<int>(c, 0));
	dp.assign(r, vector<int>(c, UNVISITED));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	cout << DFS(0, 0);

	return 0;
}

bool isValid(int row, int col) {
	if (row == -1 || row == r || col == -1 || col == c)
		return false;
	return true;
}

int DFS(int row, int col) {
	if (row == r - 1 && col == c - 1)
		return 1;

	if (dp[row][col] != UNVISITED)
		return dp[row][col];
	
	dp[row][col] = 0;
	for (int i = 0; i < 4; i++) {
		int new_row = row + dr[i];
		int new_col = col + dc[i];

		if (!isValid(new_row, new_col))
			continue;

		if (map[row][col] > map[new_row][new_col])
			dp[row][col] += DFS(new_row, new_col);
	}

	return dp[row][col];
}