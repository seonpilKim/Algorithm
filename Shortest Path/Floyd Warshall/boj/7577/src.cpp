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
const int dh[] = {1, -1};

void floyd_warshall(vector<vector<int>>& adj) {
	int n = adj.size() - 1;

	for (int mid = 0; mid <= n; mid++) {
		for (int start = 0; start <= n; start++) {
			if (adj[start][mid] == INF)
				continue;

			for (int end = 0; end <= n; end++) 
				adj[start][end] = min(adj[start][end], adj[start][mid] + adj[mid][end]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, N;
	cin >> K >> N;

	vector<vector<int>> adj(K + 1, vector<int>(K + 1, INF));
	for (int i = 0; i <= K; i++)
		adj[i][i] = 0;

	for (int i = 0; i < K; i++) {
		adj[i + 1][i] = 0;
		adj[i][i + 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		int x, y, r;
		cin >> x >> y >> r;

		adj[x - 1][y] = min(adj[x - 1][y], r);
		adj[y][x - 1] = -r;
	}

	floyd_warshall(adj);

	for (int i = 0; i <= K; i++) {
		if (adj[i][i] < 0) {
			cout << "NONE";
			return 0;
		}
	}

	for (int i = 0; i < K; i++)
		cout << (adj[0][i + 1] - adj[0][i] ? '#' : '-');

	return 0;
} 