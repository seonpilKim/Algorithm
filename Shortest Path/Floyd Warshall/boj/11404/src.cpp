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

#define MAX 100000 * 100 + 1

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> weights(n + 1, vector<int>(n + 1, MAX));

	int v1, v2, weight;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> weight;
		weights[v1][v2] = min(weights[v1][v2], weight);
	}
	
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			if (weights[start][mid] == MAX)
				continue;

			for (int end = 1; end <= n; end++) {
				if (start == end)
					continue;

				weights[start][end] = min(weights[start][end], weights[start][mid] + weights[mid][end]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			cout << (weights[i][j] == MAX ? 0 : weights[i][j]) << ' ';	
		cout << '\n';
	}

	return 0;
}