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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	priority_queue<long long, vector<long long>, less<long long>> pos;
	priority_queue<long long, vector<long long>, greater<long long>> neg;
	int zero = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n > 0)
			pos.push(n);
		else if (n < 0)
			neg.push(n);
		else
			zero++;
	}

	long long ans = 0;
	if (!pos.empty()) {
		while (pos.size() > 1) {
			if (pos.top() == 1)
				break;

			long long n = pos.top(); pos.pop();
			if (pos.top() == 1) {
				ans += n + 1;
				pos.pop();
				continue;
			}

			long long m = pos.top(); pos.pop();
			ans += n * m;
		}

		while (!pos.empty()) {
			ans += pos.top();
			pos.pop();
		}
	}

	if (!neg.empty()) {
		while (neg.size() > 1) {
			long long n = neg.top(); neg.pop();
			long long m = neg.top(); neg.pop();
			ans += n * m;
		}

		if (!zero && !neg.empty())
			ans += neg.top();
	}

	cout << ans;

	return 0;
}
