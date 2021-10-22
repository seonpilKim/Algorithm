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
const long long INF = 1e18;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

bool bellman_ford(const vector<vector<pair<int, int>>> adj, vector<long long>& dist, const int& start) {
	bool isNegativeCycle = false;
	int n = dist.size();
	dist[start] = 0;

	for (int i = 1; i < n; i++) {
		for (int cur = 1; cur < n; cur++) {
			if (dist[cur] == INF)
				continue;

			for (auto next : adj[cur]) {
				if (dist[next.first] > dist[cur] + next.second) {
					dist[next.first] = dist[cur] + next.second;
					if (i == n - 1)
						isNegativeCycle = true;
				}
			}
		}
	}

	return isNegativeCycle;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N , M;
	cin >> N >> M;

	vector<long long> dist(N + 1, INF);
	vector<vector<pair<int, int>>> adj(N + 1);
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}

	if (bellman_ford(adj, dist, 1))
		cout << -1;
	else 
		for (int i = 2; i <= N; i++)
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';

	return 0;
} 