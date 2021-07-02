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
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

#define MOD 1000000007

long long divideAndConquer(long long, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M;
	cin >> M;

	long long ans = 0;
	for (int i = 0; i < M; i++) {
		int N, S;
		cin >> N >> S;
		
		// convert to reduced fraction
		int g = gcd(N, S);
		N /= g;
		S /= g;

		// (S * Nⁿ¯²) % MOD
		ans += (S * divideAndConquer(N, MOD - 2)) % MOD;
		ans %= MOD;
	}
	
	cout << ans;

    return 0;
}

long long divideAndConquer(long long val, int pow) {
	long long res = 1;

	while (pow) {
		if (pow & 1) // if pow is odd, multiply one more time
			res = (res * val) % MOD;
		val = (val * val) % MOD;
		pow >>= 1;
	}
	
	return res;
}