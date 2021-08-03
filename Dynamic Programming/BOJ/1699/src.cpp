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

	int N;
	cin >> N;

	vector<int> dp(N + 1);
	for (int i = 1; i <= N; i++)
		dp[i] = i;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	cout << dp[N];

	return 0;
}