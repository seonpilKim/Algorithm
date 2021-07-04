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

#define MAXBIT pow(2, 10)
#define MOD (int)1e9

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(10, vector<int>(MAXBIT)));
	for (int i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;
	
	for (int n = 2; n <= N; n++) 
		for (int endNum = 0; endNum < 10; endNum++) 
			for (int bit = 0; bit < MAXBIT; bit++) 
				dp[n][endNum][bit | (1 << endNum)] = (dp[n][endNum][bit | (1 << endNum)] + (endNum == 0 ? 0 : dp[n-1][endNum-1][bit]) + (endNum == 9 ? 0 : dp[n-1][endNum+1][bit])) % MOD;
			
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i][MAXBIT - 1]) % MOD;
	cout << ans;

	return 0;
}

