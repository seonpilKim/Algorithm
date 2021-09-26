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

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<long long> dp(10001);
	fill(dp.begin(), dp.begin() + M, 1);
	dp[M] = 2;

	for (int i = M + 1; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - M]) % MOD;

	cout << dp[N];

	return 0;
}