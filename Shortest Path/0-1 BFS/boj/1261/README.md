# [[1261] μκ³ μ€ν](https://www.acmicpc.net/problem/1261)

![](imgs/1.PNG)
![](imgs/2.PNG)
![](imgs/3.PNG)
___
## π€μ κ·Ό
1. <b>λ²½μ΄ μλ μμΉλ‘ μ΄λνλ λΉμ©μ 1μ΄κ³ , λ²½μ΄ μλ μμΉλ‘ μ΄λνλ λΉμ©μ 0μ΄λ€.</b>
	- κ°μ  κ°μ€μΉκ° λ μ’λ₯λ§ μ‘΄μ¬ν  λ μ΅λ¨ κ±°λ¦¬λ₯Ό κ΅¬νλ μ΅μ μ μκ³ λ¦¬μ¦μ `0-1 BFS`μ΄λ€.
___
## π‘νμ΄
- <B>μκ³ λ¦¬μ¦ & μλ£κ΅¬μ‘°</B>
	- `0-1 BFS`
- <b>κ΅¬ν</b>
	- 0-1 BFS μκ³ λ¦¬μ¦μ κ΅¬ννμ¬ ν΄κ²° ν¨.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int BFS(const vector<vector<int>>& v, const int& N, const int& M) {
	vector<vector<bool>> isVisited(N, vector<bool>(M));

	deque<pair<int, pair<int, int>>> dq;
	dq.emplace_back(0, make_pair(0, 0));
	while (!dq.empty()) {
		int cost = dq.front().first;
		int row = dq.front().second.first;
		int col = dq.front().second.second;
		dq.pop_front();

		if (row == N - 1 && col == M - 1) 
			return cost;

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dr[i];
			int nextCol = col + dc[i];

			if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M)
				continue;
			if (isVisited[nextRow][nextCol])
				continue;

			isVisited[nextRow][nextCol] = true;
			if (v[nextRow][nextCol] == 1)
				dq.emplace_back(cost + 1, make_pair(nextRow, nextCol));
			else
				dq.emplace_front(cost, make_pair(nextRow, nextCol));
		}
	}
}
```