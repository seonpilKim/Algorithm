# [[4963] μ¬μ κ°μ](https://www.acmicpc.net/problem/4963)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
- 8λ°©ν₯μΌλ‘ μ΄μ΄μ§ λμ νλμ μ¬μ΄λΌ ν  λ, μ¬μ κ°μλ₯Ό κ΅¬νλ λ¬Έμ μ΄λ€.
___
## π‘νμ΄
- <B>μκ³ λ¦¬μ¦ & μλ£κ΅¬μ‘°</B>
	- BFS
- <b>κ΅¬ν</b>
	- 8λ°©ν₯μΌλ‘ BFS νμνμ¬ μ¬μ κ°μλ₯Ό κ΅¬νμλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
		if (m[i][j] == 0 || isVisited[i][j])
			continue;
		
		ans++;
		q.emplace(i, j);
		isVisited[i][j] = true;
		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nextRow = row + dr[i];
				int nextCol = col + dc[i];
				if (nextRow < 0 || nextCol < 0 || nextRow >= r || nextCol >= c)
					continue;
				if (isVisited[nextRow][nextCol])
					continue;
				if (m[nextRow][nextCol] == 0)
					continue;
				isVisited[nextRow][nextCol] = true;
				q.emplace(nextRow, nextCol);
			}
		}
	}
}
cout << ans << '\n';
```