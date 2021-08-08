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

int Dijkstra(const vector<vector<int>>& costs, const int& R, const int& C) {
	vector<vector<int>> pos(R, vector<int>(C, 1e9));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	
	pos[0][0] = costs[0][0];
	pq.emplace(pos[0][0], make_pair(0, 0));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int row = pq.top().second.first;
		int col = pq.top().second.second;
		pq.pop();

		if (pos[row][col] < cost)
			continue;

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dr[i];
			int nextCol = col + dc[i];

			if (nextRow < 0 || nextCol < 0 || nextRow >= R || nextCol >= C)
				continue;
			if (pos[nextRow][nextCol] <= cost + costs[nextRow][nextCol])
				continue;
			
			pos[nextRow][nextCol] = cost + costs[nextRow][nextCol];
			pq.emplace(pos[nextRow][nextCol], make_pair(nextRow, nextCol));
		}
	}

	return pos[R - 1][C - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int test_case = 1;
	while (true) {
		cin >> N;
		if (N == 0)
			break;

		vector<vector<int>> v(N, vector<int>(N));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> v[i][j];

		cout << "Problem " << test_case++ << ": " << Dijkstra(v, N, N) << '\n';
	}
	return 0;
}