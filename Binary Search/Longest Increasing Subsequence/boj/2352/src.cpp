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

	int n;
	cin >> n;
	vector<int> left(n + 1);
	for (int i = 1; i <= n; i++) {
		int right;
		cin >> right;
		left[i] = right;
	}

	vector<int> LIS;
	for (int i = 1; i <= n; i++) {
		if (LIS.empty() || LIS.back() < left[i])
			LIS.push_back(left[i]);
		else {
			int idx = lower_bound(LIS.begin(), LIS.end(), left[i]) - LIS.begin();
			LIS[idx] = left[i];
		}
	}
	cout << LIS.size();

	return 0;
}
