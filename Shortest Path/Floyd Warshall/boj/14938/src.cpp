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

#define MAX 1000000000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> item(n + 1);
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, MAX));
	
	for (int i = 1; i <= n; i++)
		cin >> item[i];

	int l1, l2, d;
	for (int i = 0; i < r; i++) {
		cin >> l1 >> l2 >> d;
		dist[l1][l2] = d;
		dist[l2][l1] = d;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			if (dist[start][mid] == MAX)
				continue;
			for (int end = 1; end <= n; end++) {
				if (start == end)
					continue;
				dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
			}
		}
	}

	int max = 0;
	int items;

	for (int start = 1; start <= n; start++) {
		items = item[start];
		for (int end = 1; end <= n; end++) {
			if (start == end)
				continue;

			if (dist[start][end] <= m) 
				items += item[end];
		}
		if (max < items)
			max = items;
	}
	
	cout << max;

    return 0;
}
