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
#include <numeric>

#define MOD 1000000003

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++) {
		dp[i][1] = i; // base condition

		for (int j = 2; j <= i / 2; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
	}

	cout << dp[N][K];

	return 0;
}