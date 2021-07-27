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

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first;
	vector<int> LIS;
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(LIS.begin(), LIS.end(), v[i].first) - LIS.begin();
		if (LIS.empty() || LIS.back() < v[i].first) 
			LIS.push_back(v[i].first);
		else 
			LIS[idx] = v[i].first;
		v[i].second = idx;
	}

	stack<int> s;
	int n = LIS.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (v[i].second == n) {
			s.push(v[i].first);
			if (--n < 0)
				break;
		}
	}

	cout << LIS.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}