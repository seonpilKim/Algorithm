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

	vector<int> seq(N);
	vector<int> dp(N);
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		dp[i] = seq[i];
		for (int j = 0; j < i; j++) 
			if (seq[j] < seq[i]) 
				dp[i] = max(dp[i], dp[j] + seq[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
	
	return 0;
}