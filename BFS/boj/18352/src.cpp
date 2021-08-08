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
#define MAX 1e3 + 1
#define MOD (int)(1e4 + 7);

const int dr[] = {0, 1, 0, -1};
const int dc[] = {-1, 0, 1, 0};

vector<int> BFS(const vector<vector<int>>& adj, const int& N, const int& src, const int& K) {
	queue<pair<int, int>> cur, next; // <dist, city>
	vector<bool> isVisited(N + 1);
	vector<int> ans;

	int dist = 0;
	isVisited[src] = true;
	next.emplace(0, src);
	while (!next.empty()) {
		while (!next.empty()) {
			cur.emplace(next.front());
			next.pop();
		}

		while (!cur.empty()) {
			int dist = cur.front().first;
			int city = cur.front().second;
			cur.pop();

			if (dist == K) {
				ans.push_back(city);
				continue;
			}

			for (int adjCity : adj[city]) {
				if (isVisited[adjCity])
					continue;

				isVisited[adjCity] = true;
				next.emplace(dist + 1, adjCity);
			}
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K, X;
	cin >> N >> M >> K >> X;
	vector<vector<int>> adj(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> citys = BFS(adj, N, X, K);
	if (citys.empty())
		cout << -1;
	else {
		sort(citys.begin(), citys.end());
		for (int city : citys)
			cout << city << '\n';
	}

	return 0;
}