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

int V;
vector<int> par;
vector<int> _rank;
vector<pair<int, int>> X, Y, Z;

int kruskal();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V;
	par.resize(V);
	_rank.assign(V, 1);
	X.resize(V);
	Y.resize(V);
	Z.resize(V);
	int x, y, z;
	for (int i = 0; i < V; i++) {
		cin >> x >> y >> z;
		X[i] = make_pair(x, i);
		Y[i] = make_pair(y, i);
		Z[i] = make_pair(z, i);
		par[i] = i;
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	cout << kruskal();

	return 0;
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

int kruskal() {
	int res = 0;
	vector<pair<int, pair<int, int>>> edges(3 * (V - 1));

	for (int i = 0, idx = 0; i < V - 1; i++, idx += 3) {
		edges[idx] = make_pair(X[i + 1].first - X[i].first, make_pair(X[i].second, X[i + 1].second));
		edges[idx + 1] = make_pair(Y[i + 1].first - Y[i].first, make_pair(Y[i].second, Y[i + 1].second));
		edges[idx + 2] = make_pair(Z[i + 1].first - Z[i].first, make_pair(Z[i].second, Z[i + 1].second));
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int weight = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		if (find(u) == find(v))
			continue;

		merge(u, v);
		res += weight;
	}
	return res;
}