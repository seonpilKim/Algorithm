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
	vector<long long> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int ans[3] = {0};
	long long min3Sum = 3e9;
	for (int i = 0; i < N - 2; i++) {
		int left = i + 1, right = N - 1;
		while (left < right) {
			long long sum = v[i] + v[left] + v[right];
			if (abs(sum) < min3Sum) {
				min3Sum = abs(sum);
				ans[0] = i;
				ans[1] = left;
				ans[2] = right;
			}
			if (sum < 0)
				left++;
			else
				right--;
		}
	}

	sort(ans, ans + 3);
	for (int i = 0; i < 3; i++)
		cout << v[ans[i]] << ' ';

	return 0;
}