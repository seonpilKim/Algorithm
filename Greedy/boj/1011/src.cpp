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
	vector<pair<long long, long long>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	for (int i = 0; i < N; i++) {
		long long dist = v[i].second - v[i].first;
		int ans = 0;

		long long n = 1;
		long long cur = 0;
		while (true) {
			if (cur + 2 * n <= dist) {
				cur += 2 * n++;
				ans += 2;
			}
			else if (cur + n <= dist) {
				cur += n;
				ans++;
			}
			else
				break;
		}
		dist -= cur;

		while (dist) {
			if (dist < n)
				n--;
			else {
				dist -= n;
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}