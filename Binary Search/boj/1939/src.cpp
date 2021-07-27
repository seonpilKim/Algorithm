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

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int N, M, src, dest, maxWeight, ans;
vector<vector<pair<int, int>>> adj;
vector<bool> isvisited;

bool BFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	adj.resize(N + 1);
	isvisited.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		maxWeight = max(maxWeight, w);
	}
	cin >> src >> dest;

	int low = 1, high = maxWeight;
	while (low <= high) {
		fill(isvisited.begin(), isvisited.end(), false);

		int mid = (low + high) / 2;

		if (BFS(mid)) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else
			high = mid - 1;
	}

	cout << ans;

	return 0;
}

bool BFS(int dist) {
	queue<int> q;
	q.push(src);
	isvisited[src] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == dest)
			return true;

		for (unsigned int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int weight = adj[cur][i].second;

			if (!isvisited[next] && dist <= weight) {
				isvisited[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}