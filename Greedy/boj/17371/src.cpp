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

int len(int x1, int x2, int y1, int y2) {
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, int>> pos(N);
	for (int i = 0; i < N; i++)
		cin >> pos[i].first >> pos[i].second;

	int minVal = INT_MAX;
	int minIdx = 0;
	for (int i = 0; i < N; i++) {
		int maxVal = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			maxVal = max(maxVal, len(pos[i].first, pos[j].first, pos[i].second, pos[j].second));
		}

		if (minVal > maxVal) {
			minVal = maxVal;
			minIdx = i;
		}
	}

	cout << pos[minIdx].first << ' ' << pos[minIdx].second;

	return 0;
}