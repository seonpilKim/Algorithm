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

using namespace std;

int N;
vector<int> SieveOfEratosthenes();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> primes = SieveOfEratosthenes();
	vector<int> sum(primes.size() + 1);
	for (int i = 1; i <= primes.size(); i++)
		sum[i] = sum[i - 1] + primes[i - 1];

	int cnt = 0;
	int first = 1, last = 1;
	while (first <= last && last <= primes.size()) {
		if (last <= primes.size() && sum[last] - sum[first - 1] >= N) {
			if (sum[last] - sum[first - 1] == N)
				cnt++;
			first++;
		}
		else
			last++;
	}
	
	cout << cnt;
	
	return 0;
}

vector<int> SieveOfEratosthenes() {
	vector<bool> numbers(N + 1, true);
	vector<int> primes;

	for (int i = 2; i <= N; i++) {
		if (!numbers[i])
			continue;

		for (int j = 2 * i; j <= N; j += i)
			numbers[j] = false;
	}

	for (int i = 2; i <= N; i++)
		if (numbers[i])
			primes.push_back(i);

	return primes;
}