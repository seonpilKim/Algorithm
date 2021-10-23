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

vector<bool> isVisited;
bool DFS(const vector<vector<pair<int, int>>> adj, const int cur, const int dest) {
	bool flag = false;
	if (cur == dest)
		return true;

	for (auto next : adj[cur]) {
		if (isVisited[next.first])
			continue;
		isVisited[next.first] = true;
		flag = (DFS(adj, next.first, dest) ? true : flag);
		isVisited[next.first] = false;
	}

	return flag;
}

bool bellman_ford(const vector<vector<pair<int, int>>> adj, vector<long long>& dist, const vector<long long>& money, const int& start, const int& dest) {
	int n = dist.size();
	bool flag = false;
	dist[start] = -money[start];

	for (int i = 0; i < n; i++) {
		for (int cur = 0; cur < n; cur++) {
			if (dist[cur] == INF)
				continue;

			for (auto next : adj[cur]) {
				if (dist[next.first] > -money[next.first] + dist[cur] + next.second) {
					dist[next.first] = -money[next.first] + dist[cur] + next.second;

					if (i == n - 1) {
						isVisited.assign(n, false);
						if (DFS(adj, next.first, dest))
							flag = true;
					}
				}
			}
		}
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, src, dest, M;
	cin >> N >> src >> dest >> M;
	vector<long long> dist(N, INF);
	vector<vector<pair<int, int>>> adj(N);
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	
	vector<long long> money(N);
	for (int i = 0; i < N; i++)
		cin >> money[i];
	
	bool flag = bellman_ford(adj, dist, money, src, dest);

	if (dist[dest] == INF)
		cout << "gg";
	else if (flag) 
		cout << "Gee";
	else
		cout << -dist[dest];

	return 0;
} 