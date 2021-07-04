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

const int MAX = 1e6;
int N;
vector<int> dp;
vector<int> before;

int DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	dp.resize(N + 1);
	before.resize(N + 1);
	
	DFS(N);
	cout << dp[N] << '\n';
	while (N) {
		cout << N << ' ';
		N = before[N];
	}

	return 0;
}

int DFS(int num) {
	if (num == 1)
		return 0;
	if (dp[num])
		return dp[num];

	int res[3] = {MAX, MAX, MAX};
	if (num % 3 == 0)
		res[0] = DFS(num / 3) + 1;
	if (num % 2 == 0)
		res[1] = DFS(num / 2) + 1;
	res[2] = DFS(num - 1) + 1;

	int minimum = min({res[0], res[1], res[2]});
	if (minimum == res[0])
		before[num] = num / 3;
	else if (minimum == res[1])
		before[num] = num / 2;
	else if (minimum == res[2])
		before[num] = num - 1;
	return dp[num] = minimum;
}