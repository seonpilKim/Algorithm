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

int N;
vector<vector<int>> board;
int maxBlock = 0;

void DFS(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	board.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	DFS(0);
	cout << maxBlock;

	return 0;
}

void move(int type) {
	queue<int> q;
	switch (type) {
		case 0: // UP
			for (int c = 0; c < N; c++) {
				for (int r = N - 1; r >= 0; r--) {
					if (board[r][c] != 0)
						q.push(board[r][c]);
					board[r][c] = 0;
				}
				int idx = N - 1;
				while (!q.empty()) {
					int data = q.front();
					q.pop();
					
					if (board[idx][c] == 0)
						board[idx][c] = data;
					else if (board[idx][c] == data)
						board[idx--][c] *= 2;
					else
						board[--idx][c] = data;
				}
			}
			break;
		case 1: // RIGHT
			for (int r = 0; r < N; r++) {
				for (int c = N - 1; c >= 0; c--) {
					if (board[r][c] != 0)
						q.push(board[r][c]);
					board[r][c] = 0;
				}
				int idx = N - 1;
				while (!q.empty()) {
					int data = q.front();
					q.pop();
					
					if (board[r][idx] == 0)
						board[r][idx] = data;
					else if (board[r][idx] == data)
						board[r][idx--] *= 2;
					else
						board[r][--idx] = data;
				}
			}
			break;
		case 2: // DOWN
			for (int c = 0; c < N; c++) {
				for (int r = 0; r < N; r++) {
					if (board[r][c] != 0)
						q.push(board[r][c]);
					board[r][c] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int data = q.front();
					q.pop();

					if (board[idx][c] == 0)
						board[idx][c] = data;
					else if (board[idx][c] == data)
						board[idx++][c] *= 2;
					else
						board[++idx][c] = data;
				}
			}
			break;
		case 3:
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (board[r][c] != 0)
						q.push(board[r][c]);
					board[r][c] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int data = q.front();
					q.pop();

					if (board[r][idx] == 0)
						board[r][idx] = data;
					else if (board[r][idx] == data)
						board[r][idx++] *= 2;
					else
						board[r][++idx] = data;
				}
			}
			break;
	}
}

void DFS(int n) {
	if (n == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				maxBlock = max(maxBlock, board[i][j]);
		return;
	}
	vector<vector<int>> copy = board;

	for (int i = 0; i < 4; i++) {
		move(i);
		DFS(n + 1);
		board = copy;
	}
}
