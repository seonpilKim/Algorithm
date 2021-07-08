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

int V, E;
vector<vector<pair<int, int>>> adj;
vector<int> par;
vector<int> _rank;

int find(int);
void merge(int, int);
int kruskal();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E;
	par.resize(V + 1);
	for (int i = 1; i <= V; i++)
		par[i] = i;
	_rank.assign(V + 1, 1);
	adj.assign(V + 1, vector<pair<int, int>>());
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	cout << kruskal();

	return 0;
}

int kruskal() {
	int res = 0;
	vector<pair<int, int>> MST;
	vector<pair<int, pair<int, int>>> edges;

	for (int u = 1; u <= V; u++) {
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			edges.emplace_back(weight, make_pair(u, v));
		}
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int weight = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		if (find(u) == find(v))
			continue;

		merge(u, v);
		MST.emplace_back(u, v);
		res += weight;
	}

	return res;
}

int find(int u) {
	if (u == par[u])
		return u;
	return par[u] = find(par[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return;
	if (_rank[u] < _rank[v])
		swap(u, v);

	par[v] = u;

	if (_rank[u] == _rank[v])
		_rank[u]++;
}