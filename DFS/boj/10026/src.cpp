#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};

vector<vector<bool>> isVisited;
void DFS(const vector<string>& v, int row, int col, char color) {
	for (int i = 0; i < 4; i++) {
		int nextRow = row + dr[i];
		int nextCol = col + dc[i];

		if (nextRow < 0 || nextCol < 0 || nextRow >= v.size() || nextCol >= v.size())
			continue;
		if (v[nextRow][nextCol] != color)
			continue;
		if (isVisited[nextRow][nextCol])
			continue;

		isVisited[nextRow][nextCol] = true;
		DFS(v, nextRow, nextCol, color);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	isVisited.assign(N, vector<bool>(N, false));

	int ans[2] = {0 , 0};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isVisited[i][j]) {
				ans[0]++;
				DFS(v, i, j, v[i][j]);
			}
		}
	}

	isVisited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			if (v[i][j] == 'G')
				v[i][j] = 'R';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isVisited[i][j]) {
				ans[1]++;
				DFS(v, i, j, v[i][j]);
			}
		}
	}
	
	cout << ans[0] << ' ' << ans[1];

	return 0;
}