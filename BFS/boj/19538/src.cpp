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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	queue<int> next, cur;
	vector<vector<int>> adj(N + 1);
	vector<bool> visited(N + 1, false);
	vector<int> ans(N + 1, -1);

	for (int u = 1; u <= N; u++) {
		int v;
		while (true) {
			cin >> v;
			if (v == 0)
				break;

			adj[u].push_back(v);
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u;
		cin >> u;

		ans[u] = 0;
		cur.push(u);
	}
	while (!cur.empty()) {
		int u = cur.front();
		cur.pop();
		for (int v : adj[u]) {
			if (ans[v] < 0 && !visited[v]) {
				next.push(v);
				visited[v] = true;
			}
		}
	}

	int time = 1;
	while (!next.empty()) {
		while (!next.empty()) {
			cur.push(next.front());
			next.pop();
		}

		while (!cur.empty()) {
			int u = cur.front();
			cur.pop();
			
			int cnt = 0;
			for (int v : adj[u]) 
				if (ans[v] >= 0) 
					cnt++;
			if (adj[u].size() <= cnt * 2) 
				next.push(u);
		}

		while (!next.empty()) {
			ans[next.front()] = time;
			cur.push(next.front());
			next.pop();
		}

		fill(visited.begin(), visited.end(), false);
		while (!cur.empty()) {
			int u = cur.front();
			cur.pop();

			for (int v : adj[u]) {
				if (ans[v] < 0 && !visited[v]) {
					next.push(v);
					visited[v] = true;
				}
			}
		}
		time++;
	}

	for (int i = 1; i <= N; i++)
		cout << ans[i] << ' ';

	return 0;
}