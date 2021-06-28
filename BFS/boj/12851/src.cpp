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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> dp(100001, INT_MAX);
	queue<int> cur, next;
	int time = 0;
	int cnt = 0;
	next.push(N);

	while (!next.empty()) {
		while (!next.empty()) {
			cur.push(next.front());
			dp[next.front()] = time;
			next.pop();
		}
		while (!cur.empty()) {
			int loc = cur.front();
			cur.pop();
			
			if (loc == K) {
				cnt++;
				continue;
			}

			if (loc > 0 && dp[loc - 1] > time)
				next.push(loc - 1);
			if (loc < 100000 && dp[loc + 1] > time)
				next.push(loc + 1);
			if (2 * loc <= 100000 && dp[2 * loc] > time)
				next.push(2 * loc);
		}
		time++;
	}

	cout << dp[K] << '\n' << cnt;

    return 0;
}
