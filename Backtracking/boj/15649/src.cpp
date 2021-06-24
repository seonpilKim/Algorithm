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
#include <sstream>

using namespace std;

int N, M;
vector<int> v;

void DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	DFS(0);

    return 0;
}

void DFS(int bitmask) {
	if (v.size() == M) {
		for (int n : v)
			cout << n << ' ';
		cout << '\n';
	}

	for (int i = 1; i <= N; i++) {
		if (bitmask & (1 << i))
			continue;
		v.push_back(i);
		DFS(bitmask | (1 << i));
		v.pop_back();
	}
}