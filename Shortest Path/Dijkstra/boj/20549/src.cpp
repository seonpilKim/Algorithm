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
const long long INF = 9e9;

int N, M;
int answer = INF;
int knight, bishop, rook;
const int knight_dr[] = {2, 1, 2, 1, -2, -1, -2, -1};
const int knight_dc[] = {1, 2, -1, -2, 1, 2, -1, -2};
const int bishop_dr[] = {1, 1, -1, -1};
const int bishop_dc[] = {1, -1, 1, -1};
const int rook_dr[] = {1, -1, 0, 0};
const int rook_dc[] = {0, 0, 1, -1};

void dijkstra(vector<int>& dist, const int& start) {
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int pos = pq.top().second;
		int row = pos / N;
		int col = pos % N;
		pq.pop();

		if (dist[pos] < curDist)
			continue;

		// knight
		for (int k = 0; k < 8; k++) {
			int nextRow = row + knight_dr[k];
			int nextCol = col + knight_dc[k];

			if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N)
				continue;

			int nextPos = nextRow * N + nextCol;
			int nextDist = knight;
			int sum = curDist + nextDist;

			if (sum < dist[nextPos]) {
				dist[nextPos] = sum;
				pq.emplace(sum, nextPos);
			}
		}

		// bishop
		for (int m = 1; m < N; m++) {
			for (int k = 0; k < 4; k++) {
				int nextRow = row + m * bishop_dr[k];
				int nextCol = col + m * bishop_dc[k];

				if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N)
					continue;

				int nextPos = nextRow * N + nextCol;
				int nextDist = bishop;
				int sum = curDist + nextDist;

				if (sum < dist[nextPos]) {
					dist[nextPos] = sum;
					pq.emplace(sum, nextPos);
				}
			}
		}

		// rook
		for (int m = 1; m < N; m++) {
			for (int k = 0; k < 4; k++) {
				int nextRow = row + m * rook_dr[k];
				int nextCol = col + m * rook_dc[k];

				if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N)
					continue;

				int nextPos = nextRow * N + nextCol;
				int nextDist = rook;
				int sum = curDist + nextDist;

				if (sum < dist[nextPos]) {
					dist[nextPos] = sum;
					pq.emplace(sum, nextPos);
				}
			}
		}
	}
}

bool isVisited[5];
void DFS(const vector<int>& pos, const vector<vector<int>>& dist, int cur, int overload, int cnt) {
	if (cnt == M) {
		answer = min(answer, overload);
		return;
	}

	for (int i = 1; i <= M; i++) {
		if (isVisited[i])
			continue;

		isVisited[i] = true;
		DFS(pos, dist, i, overload + dist[cur][pos[i]], cnt + 1);
		isVisited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	cin >> knight >> bishop >> rook;

	int row, col;
	cin >> row >> col;

	cin >> M;
	vector<int> pos(M + 1);
	vector<vector<int>> dist(M + 1, vector<int>(N * N, INF));

	pos[0] = row * N + col;
	for (int i = 1; i <= M; i++) {
		int r, c;
		cin >> r >> c;

		pos[i] = r * N + c;
	}

	for (int i = 0; i <= M; i++)
		dijkstra(dist[i], pos[i]);

	DFS(pos, dist, 0, 0, 0);

	cout << answer;

	return 0;
}