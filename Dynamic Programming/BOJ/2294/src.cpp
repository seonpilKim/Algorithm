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

	int n, k;
	cin >> n >> k;
	vector<int> coin(n);
	vector<int> dp(k + 1, NONE);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	dp[0] = 1;
	sort(coin.begin(), coin.end());

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (dp[j - coin[i]] != NONE) {
				if (dp[j] == NONE)
					dp[j] = dp[j - coin[i]] + 1;
				else
					dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			}
		}
	}
	cout << dp[k];

	return 0;
}