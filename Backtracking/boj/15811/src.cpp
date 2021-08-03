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
#define MAX 1e3 + 1
#define MOD (int)(1e4 + 7);

const int dr[] = {0, 1, 0, -1};
const int dc[] = {-1, 0, 1, 0};

bool ans;
string word[3];
vector<int> match(26, NONE);
vector<bool> isUsedNum(10);

void DFS(int n, int m, int v) {
	if (v == word[2].size()) {
		int res1 = 0, res2 = 0, sum = 0;

		for (int i = word[0].size() - 1, p = 1; i >= 0; i--, p *= 10)
			res1 += match[word[0][i] - 'A'] * p;
		for (int i = word[1].size() - 1, p = 1; i >= 0; i--, p *= 10)
			res2 += match[word[1][i] - 'A'] * p;
		for (int i = word[2].size() - 1, p = 1; i >= 0; i--, p *= 10)
			sum += match[word[2][i] - 'A'] * p;

		if (res1 + res2 == sum) {
			cout << "YES";
			exit(0);
		}
		return;
	}

	if (n < word[0].size()) {
		if (match[word[0][n] - 'A'] >= 0) {
			DFS(n + 1, m, v);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (isUsedNum[i])
				continue;

			isUsedNum[i] = true;
			match[word[0][n] - 'A'] = i;
			DFS(n + 1, m, v);
			isUsedNum[i] = false;
			match[word[0][n] - 'A'] = NONE;
		}
	}
	else if (m < word[1].size()) {
		if (match[word[1][m] - 'A'] >= 0) {
			DFS(n, m + 1, v);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (isUsedNum[i])
				continue;

			isUsedNum[i] = true;
			match[word[1][m] - 'A'] = i;
			DFS(n, m + 1, v);
			isUsedNum[i] = false;
			match[word[1][m] - 'A'] = NONE;
		}
	}
	else if (v < word[2].size()) {
		if (match[word[2][v] - 'A'] >= 0) {
			DFS(n, m, v + 1);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (isUsedNum[i])
				continue;

			isUsedNum[i] = true;
			match[word[2][v] - 'A'] = i;
			DFS(n, m, v + 1);
			isUsedNum[i] = false;
			match[word[2][v] - 'A'] = NONE;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> word[0] >> word[1] >> word[2];
	DFS(0, 0, 0);
	cout << "NO";

	return 0;
}