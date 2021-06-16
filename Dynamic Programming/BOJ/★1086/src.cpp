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

#define MAX_LENGTH 50

using namespace std;

int N, mod;
vector<string> nums;
vector<int> tenPow(MAX_LENGTH + 1);
vector<pair<int, int>> p;
vector<vector<long long>> dp;

long long DFS(int num, int bitmask);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	nums.resize(N);
	p.resize(N);

	long long totalCase = 1;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		totalCase *= (i + 1);
	}

	cin >> mod;
	dp.assign(mod + 1, vector<long long>(1 << N, -1));
	tenPow[0] = 1 % mod; // 10^0 % mod
	// a % mod == (((a / 10) % mod) * 10) % mod
	for (int i = 1; i <= MAX_LENGTH; i++)
		tenPow[i] = (tenPow[i - 1] * 10) % mod; // 10^i % mod

	for (int i = 0; i < N; i++) {
		reverse(nums[i].begin(), nums[i].end());

		// (a * b) % mod == ((a % mod) * b) % mod
		for (int j = 0; j < nums[i].size(); j++)
			p[i].first += ((nums[i][j] - '0') * tenPow[j]) % mod;
		p[i].first %= mod;
		p[i].second = nums[i].size();
	}

	long long correctCase = DFS(0, 0);
	long long g = gcd(totalCase, correctCase);

	cout << correctCase / g << '/' << totalCase / g;

	return 0;
}

long long DFS(int num, int bitmask) {
	if (bitmask == (1 << N) - 1)
		return num % mod == 0 ? true : false;
	if (dp[num][bitmask] != -1)
		return dp[num][bitmask];
	
	dp[num][bitmask] = 0;
	for (int i = 0; i < N; i++) {
		if (bitmask & (1 << i))
			continue;

		dp[num][bitmask] += DFS((num * tenPow[p[i].second] + p[i].first) % mod, bitmask | (1 << i));
	}

	return dp[num][bitmask];
}