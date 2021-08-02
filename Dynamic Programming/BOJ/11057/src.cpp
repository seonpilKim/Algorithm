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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	int N;
	cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(10));
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	
	for (int i = 2; i <= N; i++) 
		for (int j = 0; j <= 9; j++) 
			for (int k = 0; k <= j; k++) 
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;

	for (int i = 0; i <= 9; i++)
		ans = (ans + dp[N][i]) % MOD;

	cout << ans;

	return 0;
}