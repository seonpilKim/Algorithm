# [[12100] 2048 (Easy)](https://www.acmicpc.net/problem/12100)

![](imgs/1.PNG)
![](imgs/2.PNG)
![](imgs/3.PNG)
___
## π€μ κ·Ό
1. <b>κ° λΈλ‘λ€μ 4λ°©ν₯μΌλ‘ μ΄λμν¬ μ μλ€.</b>
	- μΈμ ν λ λΈλ‘μ μ«μκ° κ°μΌλ©΄, μ΄λνλ λ°©ν₯μ μμΉν λΈλ‘μΌλ‘ ν©μ²΄μν€κ³ , κ·Έ λΈλ‘μ μ«μλ λ μ«μμ ν©μ΄ λλ€.
	- μλ£κ΅¬μ‘° ν(Queue)λ₯Ό μ΄μ©νμ¬ ν μ€μ© μ²λ¦¬νμ.
	- μ΄λμ μ΅λ 5λ²κΉμ§ κ°λ₯νλ€.
___
## π‘νμ΄
- <b>λ°±νΈλνΉ(Backtracking) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- κ° λΆκΈ°λ§λ€ νμ¬ μ΄κΈ° μνμ λ³΄λλ₯Ό λ°λ‘ μ μ₯νκ³ , 4λ°©ν₯μΌλ‘ κ°κ° μ΄λμν¬ λ λ§λ€, μ΄λμ΄ λλλ©΄ μ΄κΈ° μνμ λ³΄λλ‘ μμλ³΅κ·μν¨λ€.
	- λΈλ‘μ κ° λ°©ν₯μΌλ‘ μ΄λμν¬ λλ μλ£κ΅¬μ‘° `ν(Queue)`λ₯Ό μ΄μ©νμ¬ ν μ€μ© μ²λ¦¬νμλ€.
		- νμμ νλμ© μμλ₯Ό λΉΌλ΄μ΄ μ΄λλ°©ν₯μ λλΆν° μ±μλκ°λ€.
			1. ν΄λΉ μμΉμ λΈλ‘μ΄ μμΌλ©΄, νμ¬ λΈλ‘μ μ΄λμμΌ λλλ€.
			2. ν΄λΉ μμΉμ κ°μ λΈλ‘μ΄ μμΌλ©΄, ν΄λΉ μμΉμ λΈλ‘μ μ«μλ₯Ό λ λ°° ν΄μ€λ€.
			3. ν΄λΉ μμΉμ λ€λ₯Έ λΈλ‘μ΄ μμΌλ©΄, λ€μ μμΉμ νμ¬ λΈλ‘μ μ΄λμμΌ λλλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
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
```