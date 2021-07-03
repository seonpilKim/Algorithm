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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1, vector<int>());
	vector<int> inDegree(N + 1);

	int n1, n2;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		inDegree[n2]++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= N; i++) 
		if (inDegree[i] == 0) 
			q.push(i);

	while (!q.empty()) {
		int cur = q.top();
		q.pop();

		cout << cur << ' ';

		for (int j = 0; j < adj[cur].size(); j++) {
			int next = adj[cur][j];
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}

	return 0;
}
