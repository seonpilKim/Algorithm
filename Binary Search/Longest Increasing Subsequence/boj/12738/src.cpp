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
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	vector<int> LIS;
	for (int i = 0; i < N; i++) {
		if (LIS.empty() || LIS.back() < v[i])
			LIS.push_back(v[i]);
		else {
			int idx = lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
			LIS[idx] = v[i];
		}
	}

	cout << LIS.size();

	return 0;
}
