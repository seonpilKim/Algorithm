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

	int N, K;
	cin >> N >> K;
	vector<int> sensors(N);
	for (int i = 0; i < N; i++)
		cin >> sensors[i];

	sort(sensors.begin(), sensors.end());
	sensors.erase(unique(sensors.begin(), sensors.end()), sensors.end());

	N = sensors.size();
	vector<int> diff(N - 1);
	for (int i = 0; i < N - 1; i++) 
		diff[i] = sensors[i + 1] - sensors[i];
	sort(diff.begin(), diff.end());

	int ans = 0;
	for (int i = 0; i < N - K; i++) 
		ans += diff[i];
	cout << ans;

	return 0;
}