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

using namespace std;

#define BLACK 0
#define WHITE 1

int N;
vector<vector<bool>> chess;
vector<bool> leftDiagonal;
vector<bool> rightDiagonal;
int ans[2];

void DFS(int, int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	chess.assign(N, vector<bool>(N));
	leftDiagonal.resize(2 * N);
	rightDiagonal.resize(2 * N);
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			chess[i][j] = input;
		}
	}

	DFS(0, 0, 0, BLACK);
	DFS(0, 1, 0, WHITE);
	cout << ans[0] + ans[1];
	
	return 0;
}

void DFS(int row, int col, int cnt, int color) {
	if (col >= N) {
		if (col % 2 == 0)
			col = 1;
		else
			col = 0;
		row++;
	}
	if (row == N) {
		ans[color] = max(ans[color], cnt);
		return;
	}

	if (chess[row][col] && !leftDiagonal[col - row + N - 1] && !rightDiagonal[row + col]) {
		leftDiagonal[col - row + N - 1] = rightDiagonal[row + col] = true;
		DFS(row, col + 2, cnt + 1, color);
		leftDiagonal[col - row + N - 1] = rightDiagonal[row + col] = false;
	}
	DFS(row, col + 2, cnt, color);
}
