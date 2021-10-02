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

long long moduloPow(long long x, long long power) {
	if (power == 0)
		return 1;

	long long res = moduloPow(x, power / 2);
	res = res * res % MOD;

	if (power % 2)
		return res * x % MOD;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<long long> fact(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = fact[i - 1] * i % MOD;
	
	cout << fact[N] * moduloPow(fact[M] * fact[N - M] % MOD, MOD - 2) % MOD;

	return 0;
}