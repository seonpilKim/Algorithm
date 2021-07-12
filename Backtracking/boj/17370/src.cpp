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

#define UU 0
#define UR 1
#define DR 2
#define DD 3
#define DL 4
#define UL 5

int N;
vector<vector<bool>> area;
int cnt;

void DFS(int, int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	area.assign(4 * N, vector<bool>(4 * N));
	area[2 * N][2 * N] = true;
	DFS(0, 2 * N - 1, 2 * N, UU);
	cout << cnt;

	return 0;
}

void DFS(int n, int row, int col, int dir) {
	if (n == N) {
		if (area[row][col])
			cnt++;
		return;
	}

	if (area[row][col])
		return;
	area[row][col] = true;

	if (dir == UU) {
		DFS(n + 1, row - 1, col + 1, UR);
		DFS(n + 1, row - 1, col - 1, UL);
	}
	else if (dir == UR) {
		DFS(n + 1, row - 1, col, UU);
		DFS(n + 1, row + 1, col + 1, DR);
	}
	else if (dir == DR) {
		DFS(n + 1, row + 1, col, DD);
		DFS(n + 1, row - 1, col + 1, UR);
	}
	else if (dir == DD) {
		DFS(n + 1, row + 1, col + 1, DR);
		DFS(n + 1, row + 1, col - 1, DL);
	}
	else if (dir == DL) {
		DFS(n + 1, row + 1, col, DD);
		DFS(n + 1, row - 1, col - 1, UL);
	}
	else if (dir == UL) {
		DFS(n + 1, row - 1, col, UU);
		DFS(n + 1, row + 1, col - 1, DL);
	}
	area[row][col] = false;
}