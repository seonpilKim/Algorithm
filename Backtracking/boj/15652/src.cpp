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

void DFS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	DFS();

    return 0;
}

void DFS() {
	if (v.size() == M) {
		for (int n : v)
			cout << n << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!v.empty() && v.back() > i)
			continue;

		v.push_back(i);
		DFS();
		v.pop_back();
	}
}