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
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int total;
string math_expression;
set<string> ans;
map<int, int> bracket_mapper, bit_mapper;

void DFS(int idx, int bitmask) {
	if (idx == total) {
		string answer = "";
		for (int i = 0; i < math_expression.size(); i++) {
			if (math_expression[i] == '(' || math_expression[i] == ')') {
				if ((1 << bit_mapper[i]) & bitmask)
					continue;
			}
			answer += math_expression[i];
		}
		ans.insert(answer);
		return;
	}

	for (int i = idx + 1; i <= total; i++) {
		DFS(i, bitmask | (1 << i));
		DFS(i, bitmask);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int idx = 0, cnt = 0;
	cin >> math_expression;
	for (auto cur : math_expression) {
		if (cur == '(') {
			bracket_mapper[++cnt] = idx;
			bit_mapper[idx] = ++total;
		}
		else if (cur == ')') {
			int index = bracket_mapper[cnt--];
			bit_mapper[idx] = bit_mapper[index];
		}
		idx++;
	}

	DFS(1, 0);
	DFS(1, (1 << 1));

	for (auto answer : ans) {
		if (answer == math_expression)
			continue;
		cout << answer << '\n';
	}

	return 0;
} 