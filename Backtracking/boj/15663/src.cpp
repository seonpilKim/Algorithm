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
vector<int> seq;
vector<int> result;

void DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	seq.resize(N);
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	sort(seq.begin(), seq.end());
	DFS(0);

    return 0;
}

void DFS(int bitmask) {
	if (result.size() == M) {
		for (int r : result)
			cout << r << ' ';
		cout << '\n';
		return;
	}
	vector<bool> flag(10001, false);

	for (int i = 0; i < N; i++) {
		if (bitmask & (1 << i))
			continue;
		if (flag[seq[i]] == true)
			continue;

		flag[seq[i]] = true;
		result.push_back(seq[i]);
		DFS(bitmask | (1 << i));
		result.pop_back();
	}
}