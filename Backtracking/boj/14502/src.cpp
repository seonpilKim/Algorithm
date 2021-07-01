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

int N, M;
int safeArea;
int ans = 0;
vector<vector<int>> m;
vector<vector<int>> tmp;
queue<pair<int, int>> virus;

void input();
void DFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	input();

	DFS(0, 0);
	cout << ans;

    return 0;
}

void input() {
	cin >> N >> M;
	safeArea = N * M;
	m.assign(N, vector<int>(M));
	tmp.assign(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
			if (m[i][j] != 0)
				safeArea--;
			if (m[i][j] == 2)
				virus.emplace(i, j);
		}
	}
}

void DFS(int n, int idx) {
	int size = N * M;
	if (n == 3) {
		int dr[] = {-1, 1, 0, 0};
		int dc[] = {0, 0, -1, 1};
		int infected = 0;
		tmp = m;
		queue<pair<int, int>> infects = virus;

		while (!infects.empty()) {
			int row = infects.front().first;
			int col = infects.front().second;
			infects.pop();

			for (int i = 0; i < 4; i++) {
				if (row + dr[i] < 0 || row + dr[i] >= N || col + dc[i] < 0 || col + dc[i] >= M)
					continue;

				int newRow = row + dr[i];
				int newCol = col + dc[i];
				if (tmp[newRow][newCol] == 0) {
					infected++;
					tmp[newRow][newCol] = 2;
					infects.emplace(newRow, newCol);
				}
			}
		}
		
		ans = max(ans, safeArea - infected - 3);
	
		return;
	}

	for (int i = idx; i < size; i++) {
		int row = i / M;
		int col = i % M;
		if (m[row][col] != 0)
			continue;

		m[row][col] = 1;
		DFS(n + 1, i + 1);
		m[row][col] = 0;
	}
}