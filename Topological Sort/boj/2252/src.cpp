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
	vector<int> degree(N + 1);
	vector<vector<int>> people(N + 1, vector<int>());
	
	int n1, n2;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		people[n1].push_back(n2);
		degree[n2]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (degree[i] == 0)
			q.push(i);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int i = 0; i < people[cur].size(); i++) {
			int next = people[cur][i];
			if (--degree[next] == 0)
				q.push(next);
		}
	}
	
	return 0;
}
