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
#include <limits.h>
#include <numeric>
#include <functional>

using namespace std;

#define MAX 100000 + 1

int N, K;
vector<bool> visited(MAX, false);

int BFS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;

	cout << BFS();

	return 0;
}

int BFS() {
	deque<pair<int, int>> q;
	q.emplace_back(0, N);
	visited[N] = true;

	while (!q.empty()) {
		auto p = q.front(); q.pop_front();
		int seconds = p.first;
		int location = p.second;
		
		if (location == K)
			return seconds;

		if (location * 2 < MAX && !visited[location * 2]) {
			q.emplace_front(seconds, location * 2);
			visited[location * 2] = true;
		}
		if (location + 1 < MAX && !visited[location + 1]) {
			q.emplace_back(seconds + 1, location + 1);
			visited[location + 1] = true;
		}
		if (location - 1 >= 0 && !visited[location - 1]) {
			q.emplace_back(seconds + 1, location - 1);
			visited[location - 1] = true;
		}
	}
}