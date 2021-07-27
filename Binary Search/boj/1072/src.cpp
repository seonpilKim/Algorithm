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

	double X, Y;
	cin >> X >> Y;
	int p = 100 * Y / X;

	int low = 0, high = 1e9;
	int mid;
	int ans = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		int newP = (100 * (Y + mid)) / (X + mid);
		if (newP > p) {
			high = mid - 1;
			ans = mid;
		}
		else 
			low = mid + 1;
	}

	cout << (p >= 99 ? -1 : ans);

	return 0;
}
