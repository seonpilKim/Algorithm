#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <limits.h>

#define MAX_COST 16000001

using namespace std;

int N;
vector<vector<int>> city;
vector<vector<int>> dp;

int DFS(int cur, int bitmask);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	city.assign(N, vector<int>(N));
	dp.assign(N, vector<int>(1 << N, -1));

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> city[i][j];

	cout << DFS(0, 1);
	
	return 0;
}

int DFS(int cur, int bitmask) {
	if (bitmask == (1 << N) - 1) {
		if (city[cur][0] != 0)
			return city[cur][0];
		return MAX_COST;
	}
	if (dp[cur][bitmask] != -1)
		return dp[cur][bitmask];

	dp[cur][bitmask] = MAX_COST;
	for (int i = 0; i < N; i++) {
		if (bitmask & (1 << i))
			continue;
		if (city[cur][i] == 0)
			continue;

		dp[cur][bitmask] = min(dp[cur][bitmask], DFS(i, bitmask | (1 << i)) + city[cur][i]);
	}

	return dp[cur][bitmask];
}
