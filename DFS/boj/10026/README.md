# [[10026] μ λ‘μμ½](https://www.acmicpc.net/problem/10026)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>μκ³ λ¦¬μ¦ & μλ£κ΅¬μ‘°</b>
	- `DFS`
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
void DFS(const vector<string>& v, int row, int col, char color) {
	for (int i = 0; i < 4; i++) {
		int nextRow = row + dr[i];
		int nextCol = col + dc[i];

		if (nextRow < 0 || nextCol < 0 || nextRow >= v.size() || nextCol >= v.size())
			continue;
		if (v[nextRow][nextCol] != color)
			continue;
		if (isVisited[nextRow][nextCol])
			continue;

		isVisited[nextRow][nextCol] = true;
		DFS(v, nextRow, nextCol, color);
	}
}
```