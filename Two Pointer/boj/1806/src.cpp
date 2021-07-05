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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, S;
	cin >> N >> S;
	vector<int> sum(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	if (sum[N] - sum[0] < S) {
		cout << 0;
		return 0;
	}

	int first = 1, last = 1;
	int len = N + 1;
	while (first <= last && last <= N) {
		if (last <= N && sum[last] - sum[first - 1] >= S) {
			len = min(len, last - first + 1);
			first++;
		}
		else
			last++;
	}
	
	cout << len;
	
	return 0;
}
