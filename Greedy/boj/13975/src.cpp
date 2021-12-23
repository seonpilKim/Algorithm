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
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		priority_queue<long long> pq;
		for (int i = 0; i < N; i++) {
			long long n;
			cin >> n;
			pq.push(-n);
		}

		long long ans = 0;
		while (pq.size() > 1) {
			long long sum = -pq.top(); pq.pop();
			sum += -pq.top(); pq.pop();
			ans += sum;
			pq.push(-sum);
		}
		cout << ans << '\n';
	}

	return 0;
}