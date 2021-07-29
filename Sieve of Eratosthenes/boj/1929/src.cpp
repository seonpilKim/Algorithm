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

const int MOD = 1e9 + 7;
const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

vector<int> countPrimes(const int& N, const int& M) {
	vector<bool> isPrime(M + 1, true);
	vector<int> res;

	isPrime[1] = false;

	int n = 2;
	for (int i = 2; i <= M; i++) {
		if (!isPrime[i])
			continue;

		for (int j = 2 * i; j <= M; j += i)
			isPrime[j] = false;
	}

	for (int i = N; i <= M; i++)
		if (isPrime[i])
			res.push_back(i);
	
	sort(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<int> primes = countPrimes(N, M);
	for (int n : primes)
		cout << n << '\n';


	return 0;
}