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

int BFS(const pair<int, int>&, const pair<int, int>&, const vector<vector<char>>&);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int R, C;
	cin >> R >> C;
	vector<vector<char>> board(R, vector<char>(C));

	pair<int, int> red, blue;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R')
				red = make_pair(i, j);
			else if (board[i][j] == 'B')
				blue = make_pair(i, j);
		}
	}

	cout << BFS(red, blue, board);

	return 0;
}

int BFS(const pair<int, int>& R, const pair<int, int>& B, const vector<vector<char>>& board) {
	int ans = 1;
	int dr[] = {1, 0, -1, 0};
	int dc[] = {0, 1, 0, -1};
	bool visited[10][10][10][10] = {false};

	queue<pair<int, int>> nextR, curR, nextB, curB;
	nextR.emplace(R);
	nextB.emplace(B);
	visited[R.first][R.second][B.first][B.second] = true;

	while (ans <= 10) {
		while (!nextR.empty()) {
			curR.emplace(nextR.front());
			curB.emplace(nextB.front());
			nextR.pop();
			nextB.pop();
		}

		while (!curR.empty()) {
			auto red = curR.front();
			auto blue = curB.front();
			curR.pop();
			curB.pop();

			for (int i = 0; i < 4; i++) {
				pair<int, int> newRed = red, newBlue = blue;
				bool isFind = false;
				bool isFail = false;

				while (board[newRed.first + dr[i]][newRed.second + dc[i]] != '#') {
					newRed.first += dr[i];
					newRed.second += dc[i];
					if (board[newRed.first][newRed.second] == 'O') {
						isFind = true;
						break;
					}
				}
				while (board[newBlue.first + dr[i]][newBlue.second + dc[i]] != '#') {
					newBlue.first += dr[i];
					newBlue.second += dc[i];
					if (board[newBlue.first][newBlue.second] == 'O') {
						isFail = true;
						break;
					}
				}

				if (isFail)
					continue;
				else if (newRed == newBlue) { 
					if (isFind) 
						return ans;
					if (dr[i] + dc[i] > 0) {
						if (red > blue) {
							newBlue.first -= dr[i];
							newBlue.second -= dc[i];
						}
						else {
							newRed.first -= dr[i];
							newRed.second -= dc[i];
						}
					}
					else { 
						if (red < blue) {
							newBlue.first -= dr[i];
							newBlue.second -= dc[i];
						}
						else {
							newRed.first -= dr[i];
							newRed.second -= dc[i];
						}
					}
				}
				else if (isFind) 
					return ans;

				if (!visited[newRed.first][newRed.second][newBlue.first][newBlue.second]) {
					visited[newRed.first][newRed.second][newBlue.first][newBlue.second] = true;
					nextR.push(newRed);
					nextB.push(newBlue);
				}
			}
		}

		ans++;
	}

	return -1;
}