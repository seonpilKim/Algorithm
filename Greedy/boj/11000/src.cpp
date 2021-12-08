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
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int n, m;
		cin >> n >> m;
		v[i] = {n, m};
	}
	sort(v.begin(), v.end());

	priority_queue<int> pq;
	pq.push(-v.front().second);

	int ans = 1;
	for (int i = 1; i < N; i++) {
		while (!pq.empty() && -pq.top() <= v[i].first)
			pq.pop();
		pq.push(-v[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;
	
	return 0;
}