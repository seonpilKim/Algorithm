# [[1987] ์ํ๋ฒณ](https://www.acmicpc.net/problem/1987)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
1. <b>์ด๋ฏธ ์ง๋๊ฐ ์ํ๋ฒณ ์๋ฆฌ๋ ์ง๋๊ฐ์ง ์์ผ๋ฉด์, ๊ฐ์ฅ ๋ง์ ์นธ์ ์ง๋  ์ ์๋ ๊ฒฝ์ฐ์ ์ ์ฐพ๊ธฐ</b>
	- ๋ฐฑํธ๋ํน ์๊ณ ๋ฆฌ์ฆ์ผ๋ก ํด๊ฒฐํ์.
	- ์ค๋ณต ์ฌ๋ถ๋ ์ด๋ป๊ฒ ์ฒดํฌํ ๊น?
		1. unordered_set
		2. ๋นํธ๋ง์คํน or boolํ ๋ฐฐ์ด
___
## ๐กํ์ด
- <b>๋ฐฑํธ๋ํน(Back-Tracking) ์๊ณ ๋ฆฌ์ฆ</b>์(๋ฅผ) ์ฌ์ฉํ์๋ค.
__
## โ ํผ๋๋ฐฑ
1. <b>์ค๋ณต ์ฌ๋ถ ์ฒดํฌ๋ ๋นํธ๋ง์คํน or boolํ ๋ฐฐ์ด๋ก ํ๋ ๊ฒ์ด ํจ์จ์ ์ด๋ค.</b>
	- ์ฒ์์๋ set ์๋ฃ๊ตฌ์กฐ๋ฅผ ์ด์ฉํ์ฌ ์ฒดํฌํ์ง๋ง, ์๊ฐ ์ด๊ณผ๋ฅผ ๋ฐ์๋ค.
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
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
		alphabet[board[newRow][newCol] - 'A'] = false; // back-tracking
	}
}
```