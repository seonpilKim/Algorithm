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

	int T, N, K;
	vector<int> result;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<int> dp(N + 1);
		vector<int> delay(N + 1);
		vector<int> inDegree(N + 1);
		vector<vector<int>> adj(N + 1, vector<int>());
		for (int i = 1; i <= N; i++)
			cin >> delay[i];
		int n1, n2;
		for (int i = 0; i < K; i++) {
			cin >> n1 >> n2;
			adj[n1].push_back(n2);
			inDegree[n2]++;
		}
		int number;
		cin >> number;

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (inDegree[i] == 0)
				q.push(i);
			dp[i] = delay[i];
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i];
				dp[next] = max(dp[next], dp[cur] + delay[next]);
				if (--inDegree[next] == 0) 
					q.push(next);
			}
		}

		result.push_back(dp[number]);
	}

	for (int r : result)
		cout << r << '\n';

	return 0;
}
