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

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

void dijkstra(const vector<vector<pair<int, int>>>& adj, vector<int>& dist, const int& start) {
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (dist[pos] < curDist)
			continue;

		for (auto dest : adj[pos]) {
			int nextPos = dest.first;
			int nextDist = dest.second;
			int sum = curDist + nextDist;

			if (dist[nextPos] > sum) {
				dist[nextPos] = sum;
				pq.emplace(sum, nextPos);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, M;
	cin >> V >> M;

	vector<vector<pair<int, int>>> adj(V + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	int J, S;
	cin >> J >> S;

	vector<int> distJ(V + 1, INF), distS(V + 1, INF);

	dijkstra(adj, distJ, J);
	dijkstra(adj, distS, S);

	int minDist = INF;
	for (int start = 1; start <= V; start++)
		if (start != J && start != S)
			minDist = min(minDist, distJ[start] + distS[start]);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int start = 1; start <= V; start++) 
		if (start != J && start != S)
			if (distJ[start] <= distS[start]) 
				if (distJ[start] + distS[start] == minDist)
					pq.emplace(distJ[start], start);

	cout << (pq.empty() ? -1 : pq.top().second);

	return 0;
}