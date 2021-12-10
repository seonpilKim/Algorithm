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

	int N, K;
	cin >> N >> K;
	vector<int> dist(N - 1);
	
	int cur, prev;
	cin >> prev;
	for (int i = 0; i < N - 1; i++) {
		cin >> cur;
		dist[i] = cur - prev;
		prev = cur;
	}
	sort(dist.begin(), dist.end());

	int ans = 0;
	for (int i = 0; i < N - K; i++)
		ans += dist[i];
	cout << ans;

	return 0;
}