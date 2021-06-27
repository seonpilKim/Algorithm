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

#define SIZE 9
#define MAX SIZE * SIZE

vector<vector<int>> sudoku(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> rows(SIZE, vector<bool>(SIZE + 1, true));
vector<vector<bool>> cols(SIZE, vector<bool>(SIZE + 1, true));
vector<vector<bool>> sqr(SIZE, vector<bool>(SIZE + 1, true));

void DFS(int);
int changeToSquareIdx(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> sudoku[i][j];

			if (sudoku[i][j]) {
				rows[i][sudoku[i][j]] = false;
				cols[j][sudoku[i][j]] = false;
				sqr[changeToSquareIdx(i, j)][sudoku[i][j]] = false;
			}
		}
	}

	DFS(0);

    return 0;
}

int changeToSquareIdx(int row, int col) {
	return ((row / 3) * 3) + (col / 3);
}

void print() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			cout << sudoku[i][j] << ' ';
		cout << '\n';
	}
	exit(0);
}

void DFS(int N) {
	if (N == MAX)
		print();
	
	int row = N / SIZE;
	int col = N % SIZE;

	if (sudoku[row][col])
		DFS(N + 1);
	else {
		for (int i = 1; i <= SIZE; i++) {
			if (rows[row][i] && cols[col][i] && sqr[changeToSquareIdx(row, col)][i]) {
				sudoku[row][col] = i;
				rows[row][i] = cols[col][i] = sqr[((row / 3) * 3) + (col / 3)][i] = false;
				DFS(N + 1);
				sudoku[row][col] = 0;
				rows[row][i] = cols[col][i] = sqr[((row / 3) * 3) + (col / 3)][i] = true;
			}
		}
	}
}