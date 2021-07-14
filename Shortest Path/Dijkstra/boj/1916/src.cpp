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

#define INF INT_MAX

int N, M;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<int>> adj;
vector<int> cost;

int Dijkstra();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	adj.assign(N + 1, vector<int>(N + 1, -1));
	cost.assign(N + 1, INF);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (adj[u][v] == -1 || adj[u][v] > w)
			adj[u][v] = w;
	}

	cout << Dijkstra();

	return 0;
}

int Dijkstra() {
	int start, dest;
	cin >> start >> dest;

	cost[start] = 0;
	pq.emplace(start, cost[start]);

	while (!pq.empty()) {
		int curCity = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();

		if (cost[curCity] < curCost)
			continue;

		for (int nextCity = 1; nextCity <= N; nextCity++) {
			if (adj[curCity][nextCity] == -1)
				continue;

			int nextCost = curCost + adj[curCity][nextCity];
			if (cost[nextCity] > nextCost) {
				cost[nextCity] = nextCost;
				pq.emplace(nextCity, nextCost);
			}
		}
	}

	return cost[dest];
}