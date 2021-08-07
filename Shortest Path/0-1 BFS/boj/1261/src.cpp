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

const int dr[] = {0, 1, 0, -1};
const int dc[] = {-1, 0, 1, 0};

int BFS(const vector<vector<int>>& v, const int& N, const int& M) {
	vector<vector<bool>> isVisited(N, vector<bool>(M));

	deque<pair<int, pair<int, int>>> dq;
	dq.emplace_back(0, make_pair(0, 0));
	while (!dq.empty()) {
		int cost = dq.front().first;
		int row = dq.front().second.first;
		int col = dq.front().second.second;
		dq.pop_front();

		if (row == N - 1 && col == M - 1) 
			return cost;

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dr[i];
			int nextCol = col + dc[i];

			if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M)
				continue;
			if (isVisited[nextRow][nextCol])
				continue;

			isVisited[nextRow][nextCol] = true;
			if (v[nextRow][nextCol] == 1)
				dq.emplace_back(cost + 1, make_pair(nextRow, nextCol));
			else
				dq.emplace_front(cost, make_pair(nextRow, nextCol));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> M >> N;

	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int j = 0;
		for (auto s : str) 
			v[i][j++] = s - '0';
	}

	cout << BFS(v, N, M);

	return 0;
}