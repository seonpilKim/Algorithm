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
	vector<pair<long long, long long>> pos(N);

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> pos[i].first >> pos[i].second;
		sum += pos[i].second;
	}
	sort(pos.begin(), pos.end());

	long long cur = 0;
	for (int i = 0; i < N; i++) {
		cur += pos[i].second;
		if (cur >= (sum + 1) / 2) {
			cout << pos[i].first;
			break;
		}
	}

	return 0;
}