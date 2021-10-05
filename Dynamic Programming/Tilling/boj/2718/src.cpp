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
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 9e9;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> dp(30 + 1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 5;

	for (int i = 3; i <= 30; i++) {
		dp[i] = dp[i - 1] + 4 * dp[i - 2];
		for (int j = 3; j <= i; j++)
			dp[i] += (j % 2 ? 2 * dp[i - j] : 3 * dp[i - j]);

		if (dp[i] > 2147483647)
			break;
	}

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		cout << dp[N] << '\n';
	}


	return 0;
}