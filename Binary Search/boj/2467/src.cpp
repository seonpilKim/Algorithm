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
	bool hasNegative = false, hasPositive = false;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (hasNegative == false && v[i] < 0)
			hasNegative = true;
		if (hasPositive == false && v[i] > 0)
			hasPositive = true;
	}

	int idx[2] = {0};
	int minSum = 2e9;
	if (hasNegative && hasPositive) { // Negative + Positive
		for (int i = 0; i < N - 1; i++) {
			int low = i + 1, high = N - 1;
			int mid, cur = v[i], target;
			while (low <= high) {
				mid = (low + high) / 2;
				target = v[mid];

				if (cur + target > 0)
					high = mid - 1;
				else
					low = mid + 1;

				if (minSum > abs(cur + target)) {
					minSum = abs(cur + target);
					idx[0] = i;
					idx[1] = mid;
				}
			}
		}
	}
	else if (hasNegative) { // only Negative
		idx[0] = N - 2;
		idx[1] = N - 1;
	}
	else if (hasPositive) { // only Positive
		idx[0] = 0;
		idx[1] = 1;
	}

	cout << v[idx[0]] << ' ' << v[idx[1]];

	return 0;
}