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

int N, cnt;
vector<int> columns;

void DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	columns.assign(N + 1, 0);
	DFS(1);
	cout << cnt;

    return 0;
}

bool checkValid(int row, int col) {
	for (int r = 1; r < row; r++) {
		if (columns[r] == col)
			return false;
		if (abs(r - row) == abs(columns[r] - col))
			return false;
	}
	return true;
}

void DFS(int row) {	
	if (row == N + 1) {
		cnt++;
		return;
	}

	for (int col = 1; col <= N; col++) {
		if (checkValid(row, col)) {
			columns[row] = col;
			DFS(row + 1);
		}
	}
}