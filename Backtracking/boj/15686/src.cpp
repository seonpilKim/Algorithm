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
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int ans = 100000000;

void DFS(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	int input;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			if (input == 1)
				house.emplace_back(i, j);
			else if (input == 2)
				chicken.emplace_back(i, j);
		}
	}

	DFS(0, 0, 0);

	cout << ans;

    return 0;
}

void DFS(int n, int idx, int bitmask) {
	if (n == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int chickenRoad = 100000000;
			for (int j = 0; j < chicken.size(); j++) 
				if (bitmask & (1 << j)) 
					chickenRoad = min(chickenRoad, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));	
			sum += chickenRoad;
		}

		ans = min(ans, sum);
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		if (bitmask & (1 << i))
			continue;

		DFS(n + 1, i + 1, bitmask | (1 << i));
	}
}