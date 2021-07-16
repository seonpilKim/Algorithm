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

	int N, K;
	cin >> N >> K;

	vector<int> coin(N);
	for (int i = 0; i < N; i++)
		cin >> coin[i];
	sort(coin.begin(), coin.end(), less<int>());

	int ans = 0;
	int cur = 0;
	int idx = coin.size() - 1;

	while (cur != K) {
		if (coin[idx] > K - cur)
			idx--;
		else {
			cur += coin[idx];
			ans++;
		}
	}

	cout << ans;

	return 0;
}
