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
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int L, P, V;
	int T = 1;
	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;

		cout << "Case " << T++ << ": ";
		cout << L * (V / P) + (V % P > L ? L : V % P) << '\n';
	}

	return 0;
}
