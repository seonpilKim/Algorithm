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

const int MOD = 1e4 + 7;
const int dr[] = {0, 1, 0, -1};
const int dc[] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> dp(N);

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < N; i++) 
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;

	cout << dp[N - 1];

	return 0;
}