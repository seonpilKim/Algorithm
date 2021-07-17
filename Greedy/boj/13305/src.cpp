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

	vector<int> km(N);
	vector<int> cost(N);
	for (int i = 1; i < N; i++)
		cin >> km[i];
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	int idx = 0;
	long long cnt, cur;
	long long ans = 0;
	while (idx + 1 < N) {
		cur = cost[idx];
		cnt = km[++idx];
		while (idx + 1 < N && cur <= cost[idx]) 
			cnt += km[++idx];
		ans += cur * cnt;
	}

	cout << ans;

	return 0;
}