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

vector<bool> isPrime(1e6 + 1, true);

void findPrimes() {
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= 1e6; i++) {
		if (!isPrime[i])
			continue;

		for (int j = 2 * i; j <= 1e6; j += i)
			isPrime[j] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	findPrimes();

	while (true) {
		cin >> N;
		if (N == 0)
			break;

		for (int i = 3; i <= N / 2; i += 2) {
			if (isPrime[N - i]) {
				cout << N << " = " << i << " + " << N - i << '\n';
				break;
			}
		}
	}

	return 0;
}