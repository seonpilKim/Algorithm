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

#define NONE -1

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> trees(N);
	int totalHeight = 0;
	int countRaise2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		totalHeight += trees[i];
		countRaise2 += trees[i] / 2;
	}

	if (totalHeight % 3)
		cout << "NO";
	else {
		if (countRaise2 >= totalHeight / 3)
			cout << "YES";
		else
			cout << "NO";
	}

	return 0;
}
