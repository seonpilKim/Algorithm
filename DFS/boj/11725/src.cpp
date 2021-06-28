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
#include <limits.h>
#include <numeric>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
vector<int> parent;

void DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	edges.assign(N + 1, vector<int>());
	visited.assign(N + 1, false);
	parent.assign(N + 1, 0);

	int v1, v2;
	for (int i = 1; i < N; i++) {
		cin >> v1 >> v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}
	
	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}

void DFS(int par) {
	visited[par] = true;

	for (int v : edges[par]) {
		if (visited[v] == false) {
			parent[v] = par;
			DFS(v);
		}
	}
}