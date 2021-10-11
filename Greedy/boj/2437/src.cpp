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

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) 
		cin >> v[i];
	sort(v.begin(), v.end());

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + 1 < v[i]) 
			break;

		sum += v[i];
	}
	cout << sum + 1;

	return 0;
}