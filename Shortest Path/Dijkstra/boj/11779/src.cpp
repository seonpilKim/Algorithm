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

#define INF 1000000000
#define NONE -1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

// input
	int n, m;
	cin >> n >> m;
	vector<vector<int>> costs(n + 1, vector<int>(n + 1, NONE));
	int v1, v2, cost;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> cost;
		if (costs[v1][v2] == NONE)
			costs[v1][v2] = cost;
		else
			costs[v1][v2] = min(costs[v1][v2], cost);
	}
	int start, dest;
	cin >> start >> dest;

// Dijkstra
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> lastCity(n + 1);
	vector<int> citys(n + 1, INF);
	citys[start] = 0;
	pq.emplace(start, citys[start]);
	while (!pq.empty()) {
		int curCity = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();

		if (citys[curCity] < curCost)
			continue;

		for (int nextCity = 1; nextCity <= n; nextCity++) {
			if (costs[curCity][nextCity] == NONE)
				continue;

			int nextCost = curCost + costs[curCity][nextCity];
			if (citys[nextCity] > nextCost) {
				citys[nextCity] = nextCost;
				lastCity[nextCity] = curCity; // renew the route
				pq.emplace(nextCity, nextCost);
			}
		}
	}

// Find route
	stack<int> route;
	int city = dest;
	while (city != start) {
		route.push(city);
		city = lastCity[city];
	}
	route.push(start);

// Answer
	cout << citys[dest] << '\n';
	cout << route.size() << '\n';
	while (!route.empty()) {
		cout << route.top() << ' ';
		route.pop();
	}

    return 0;
}
