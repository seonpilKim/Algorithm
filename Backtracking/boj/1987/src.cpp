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

int R, C;
int cnt;
vector<vector<char>> board;

bool alphabet[26];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void DFS(int, int, int);
void input();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	input();

	DFS(1, 0, 0);
	cout << cnt;

	return 0;
}

void input() {
	cin >> R >> C;
	board.assign(R, vector<char>(C));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	alphabet[board[0][0] - 'A'] = true;
}

void DFS(int n, int row, int col) {
	if (n > cnt)
		cnt = n;

	for (int i = 0; i < 4; i++) {
		int newRow = row + dr[i];
		int newCol = col + dc[i];

		if (newRow < 0 || newCol < 0 || newRow >= R || newCol >= C)
			continue;
		if (alphabet[board[newRow][newCol] - 'A'] == true)
			continue;

		alphabet[board[newRow][newCol] - 'A'] = true;
		DFS(n + 1, newRow, newCol);
		alphabet[board[newRow][newCol] - 'A'] = false;
	}
}