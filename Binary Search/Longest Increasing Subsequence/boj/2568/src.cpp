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

#define NONE -1

const int MOD = 1e9 + 7;
const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, int>> v(5e5 + 1, {NONE, NONE});
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].first = n2;
	}

	vector<int> LIS;
	for (int i = 1; i <= 5e5; i++) {
		if (v[i].first == NONE)
			continue;

		int idx = lower_bound(LIS.begin(), LIS.end(), v[i].first) - LIS.begin();
		if (LIS.empty() || LIS.back() < v[i].first)
			LIS.push_back(v[i].first);
		else 
			LIS[idx] = v[i].first;
		v[i].second = idx;
	}
	
	vector<int> ans;
	int n = LIS.size() - 1;
	for (int i = 5e5; i >= 1; i--) {
		if (v[i].first == NONE)
			continue;

		if (n >= 0 && v[i].second == n)
			n--;
		else
			ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	cout << N - LIS.size() << '\n';
	for (int a : ans)
		cout << a << '\n';

	return 0;
}