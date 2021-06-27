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

int N;
vector<vector<int>> ability;
int minValue = 1001;

void DFS(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	ability.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ability[i][j];
	
	DFS(1, 1, 1);
	cout << minValue;

    return 0;
}

void DFS(int n, int idx, int bitmask) {
	if (n == N / 2) {
		int start = 0, link = 0;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if ((bitmask & (1 << i)) && (bitmask & (1 << j)))
					start += (ability[i][j] + ability[j][i]);
				if (!(bitmask & (1 << i)) && !((bitmask & (1 << j))))
					link += (ability[i][j] + ability[j][i]);
			}
		}
		
		int result = abs(start - link);
		if(minValue > result)
			minValue = result;

		return;
	}


	for (int i = idx; i < N; i++) {
		if (bitmask & (1 << i))
			continue;

		bitmask |= (1 << i);
		DFS(n + 1, i + 1, bitmask);
		bitmask &= ~(1 << i);
	}
}