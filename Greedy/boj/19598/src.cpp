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
	vector<pair<int, int>> meetings(N);
	for (int i = 0; i < N; i++) 
		cin >> meetings[i].first >> meetings[i].second;
	sort(meetings.begin(), meetings.end());

	int ans = 0;
	priority_queue<int> rooms;
	for (auto meeting : meetings) {
		int start = meeting.first, end = meeting.second;
		while (!rooms.empty() && start >= -rooms.top()) 
			rooms.pop();
		rooms.push(-end);

		ans = max(ans, (int)rooms.size());
	}

	cout << ans;

	return 0;
}