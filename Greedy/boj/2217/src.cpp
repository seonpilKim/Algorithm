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
	vector<int> weight(N);
	for (int i = 0; i < N; i++)
		cin >> weight[i];

	int ans = 0;
	sort(weight.begin(), weight.end(), greater<int>());
	while (!weight.empty()) {
		ans = max(ans, weight.back() * N--);
		weight.pop_back();
	}

	cout << ans;

	return 0;
}