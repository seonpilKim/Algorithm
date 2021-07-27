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
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first;
	vector<int> LIS;
	vector<vector<long long>> num(N + 1), cnt(N + 1, vector<long long>(1, 0));
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(LIS.begin(), LIS.end(), v[i].first) - LIS.begin();
		if (LIS.empty() || LIS.back() < v[i].first) 
			LIS.push_back(v[i].first);
		else 
			LIS[idx] = v[i].first;
		v[i].second = idx + 1;
	}

	int lenLIS = LIS.size();
	for (int i = N - 1; i >= 0; i--) {
		int curLenCnt, len = v[i].second;

		if (len == lenLIS)
			curLenCnt = 1;
		else {
			int idx = upper_bound(num[len + 1].begin(), num[len + 1].end(), v[i].first) - num[len + 1].begin();
			curLenCnt = (cnt[len + 1].back() - cnt[len + 1][idx] + MOD) % MOD;
		}

		num[len].push_back(v[i].first);
		cnt[len].push_back((curLenCnt + cnt[len].back()) % MOD);
	}

	cout << lenLIS << ' ' << cnt[1].back();

	return 0;
}