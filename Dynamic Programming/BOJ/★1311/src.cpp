#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>

#define MAX_COST 200001

using namespace std;

int N;
vector<vector<int>> v;
vector<vector<int>> dp;

int DFS(int n, int bitmask);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	v.assign(N, vector<int>(N));
	dp.assign(N, vector<int>(1 << 20, -1));

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> v[i][j];

	cout << DFS(0, 0);

	return 0;
}

int DFS(int n, int bitmask) {
	if (bitmask == (1 << N) - 1)
		return 0;
	if (dp[n][bitmask] != -1)
		return dp[n][bitmask];

	dp[n][bitmask] = MAX_COST;
	for (int i = 0; i < N; i++) {
		if (bitmask & (1 << i))
			continue;
		
		dp[n][bitmask] = min(dp[n][bitmask], DFS(n + 1, bitmask | (1 << i)) + v[n][i]);
	}

	return dp[n][bitmask];
}