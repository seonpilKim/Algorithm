# [[13460] ๊ตฌ์ฌ ํ์ถ 2](https://www.acmicpc.net/problem/13460)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
1. <b>๋ณด๋๋ฅผ 4๋ฐฉํฅ์ผ๋ก๋ง ๊ธฐ์ธ์ฌ์ ๋นจ๊ฐ๊ตฌ์ฌ๋ง ๊ตฌ๋ฉ์ผ๋ก ๋ฃ๋ ๊ฒฝ๋ก๋ฅผ ๊ตฌํด์ผ ํ๋ค.</b>
	- ๋ณด๋๋ฅผ ์ต๋ 10๋ฒ๊น์ง๋ง ๊ธฐ์ธ์ฌ๋ณด๋ฏ๋ก, BFS์ ์ด์ฉํ์ฌ ์ต๋ 4ยนโฐ๋ฒ ์ด๋ด๋ก ๋น ๋ฅด๊ฒ ํด๋ฅผ ๊ตฌํ  ์ ์๋ค.
___
## ๐กํ์ด
- <b>๋๋น ์ฐ์  ํ์(BFS)</b>์(๋ฅผ) ์ฌ์ฉํ์๋ค.
	- ๊ตฌ์ฌ ๋ฐฐ์น์ ๊ฒฝ์ฐ์ ์๋ ๋ค์๊ณผ ๊ฐ๋ค.
		1. R, B, ๊ตฌ๋ฉ์ด ๋์ผ ์ ์์ ์์นํ ๊ฒฝ์ฐ
			> ex) `#RB..O#` or `#BR..O#`
		2. R๊ณผ B ์ฌ์ด์ ๊ตฌ๋ฉ์ด ์กด์ฌํ๋ ๊ฒฝ์ฐ
			> ex) `#R..O.B#`
		3. R๊ณผ B๊ฐ ๋์ผ ์ ์์ด ์๋ ๊ฒฝ์ฐ
	- ์์์ ์ฐพ์ ๊ฐ๊ฐ์ ๊ฒฝ์ฐ์ ์๋ฅผ ์ฐธ๊ณ ํ์ฌ, ๋ค์๊ณผ ๊ฐ์ด ๊ตฌํํ์๋ค.
		1. ๋นจ๊ฐ๊ตฌ์ฌ -> ํ๋๊ตฌ์ฌ ์์๋ก ๊ธฐ์ธ์ฌ ๋ณธ๋ค.
			- ๊ตฌ์ฌ์ด ์ด๋ํ๋ ๊ณผ์ ์์ ๊ตฌ๋ฉ์ ๋ง๋๋ค๋ฉด, ๋ฐ๋ก ํ์ํ๊ณ  ์ผ๋จ ๊ณ์ ์ด๋์ํจ๋ค.
		2. ๋ง์ฝ, ํ๋๊ตฌ์ฌ์ด ๊ตฌ๋ฉ์ ๋ง๋ฌ์๋ค๋ฉด, `์คํจ`.
		3. ๊ทธ๋ ์ง ์๊ณ  ๋ง์ฝ, ๋นจ๊ฐ๊ตฌ์ฌ๊ณผ ํ๋๊ตฌ์ฌ์ด ๊ฒน์ณ์๋ค๋ฉด, ๋ค์ ์กฐ๊ฑด์ ๋ฐ์ ธ๋ณด์.
			1. ๋นจ๊ฐ๊ตฌ์ฌ์ด ๊ตฌ๋ฉ์ ๋ง๋ฌ์๋ค๋ฉด, `์ฑ๊ณต`.
				- `#R..0..B#` ์ํ์์ ์ค๋ฅธ์ชฝ์ผ๋ก ๊ธฐ์ธ์ธ ์ํฉ์ผ๋ก ์ดํดํ์.
			2. ๊ทธ๋ ์ง ์๋ค๋ฉด, ๊ตฌ์ฌ ์์น๋ฅผ ์กฐ์ ํ๋ค.
				- ์๋ฅผ๋ค์ด, ๋นจ๊ฐ๊ตฌ์ฌ์ด ๋จผ์  ๋ฒฝ์ ๋ฟ์ ๊ฒฝ์ฐ, ํ๋๊ตฌ์ฌ์ ๋ค๋ก ํ ์นธ ์ด๋์ํค๋ ์์ผ๋ก ์กฐ์ 
		4. ๊ทธ๋ ์ง ์๊ณ  ๋ง์ฝ, ๋นจ๊ฐ๊ตฌ์ฌ์ด ๊ตฌ๋ฉ์ ๋ง๋ฌ์๋ค๋ฉด, `์ฑ๊ณต`.
		5. ์ฑ๊ณต or ์คํจํ ๊ฒฝ์ฐ๊ฐ ์๋๋ผ๋ฉด, ๋ ๊ตฌ์ฌ ์์น์ ๋ฐฉ๋ฌธ์ํ๋ฅผ ์ฒดํฌํ์.
			- ๋ ๊ตฌ์ฌ์ ์์น๋ฅผ ๋์์ ์ฒดํฌํด์ผ ํ๋ค.
			- ๋ฏธ๋ฐฉ๋ฌธ ์ํ๋ผ๋ฉด, ๋ค์์ ๊ธฐ์ธ์ผ ํ์ ์ด๋๋ ๋ ๊ตฌ์ฌ ์์น๋ฅผ pushํ๊ณ , ๋ฐฉ๋ฌธ์ํ๋ฅผ true๋ก ๋ณ๊ฒฝ
		6. ์ ๊ณผ์ ์ ์ต๋ 10๋ฒ ๊ธฐ์ธ์ผ ๋๊น์ง ๋ฐ๋ณตํ๊ณ , ์ดํ๋ก๋ `์คํจ`๋ก ๊ฐ์ฃผํ๋ค.	
___
## โ ํผ๋๋ฐฑ
1. <b>ํ... ์ด๋ฐ ๋ฌธ์ ๋ ์ ์ํ๊ณ  ํ์..๐ฉ</b>
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
int BFS(const pair<int, int>& R, const pair<int, int>& B, const vector<vector<char>>& board) {
	int ans = 1;
	int dr[] = {1, 0, -1, 0};
	int dc[] = {0, 1, 0, -1};
	bool visited[10][10][10][10] = {false}; // ๋ ๊ตฌ์ฌ์ ํด๋น ์์น ๋ฐฉ๋ฌธ ์ฌ๋ถ

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

				while (board[newRed.first + dr[i]][newRed.second + dc[i]] != '#') { // R ๊ธฐ์ธ์ด๊ธฐ
					newRed.first += dr[i];
					newRed.second += dc[i];
					if (board[newRed.first][newRed.second] == 'O') {
						isFind = true;
						break;
					}
				}
				while (board[newBlue.first + dr[i]][newBlue.second + dc[i]] != '#') { // B ๊ธฐ์ธ์ด๊ธฐ
					newBlue.first += dr[i];
					newBlue.second += dc[i];
					if (board[newBlue.first][newBlue.second] == 'O') {
						isFail = true;
						break;
					}
				}

				if (isFail) // B๊ฐ ๊ตฌ๋ฉ์ ๋น ์ง ๊ฒฝ์ฐ
					continue;
				else if (newRed == newBlue) { // R๊ณผ B๊ฐ ๊ฒน์น ๊ฒฝ์ฐ
					if (isFind) // R์ด ๊ตฌ๋ฉ์ ์ง๋์ B๋ ๊ฒน์น ๊ฒฝ์ฐ(=R๋ง ๊ตฌ๋ฉ์ ๋น ์ง ๊ฒฝ์ฐ)
						return ans;
					if (dr[i] + dc[i] > 0) { // ์ฐ์ธก or ํ๋จ์ผ๋ก ๊ธฐ์ธ์ธ ๊ฒฝ์ฐ
						if (red > blue) { // ->BR#
							newBlue.first -= dr[i];
							newBlue.second -= dc[i];
						}
						else { // ->RB#
							newRed.first -= dr[i];
							newRed.second -= dc[i];
						}
					}
					else { // ์ข์ธก or ์๋จ์ผ๋ก ๊ธฐ์ธ์ธ ๊ฒฝ์ฐ
						if (red < blue) { // #RB<-
							newBlue.first -= dr[i];
							newBlue.second -= dc[i];
						}
						else { // #BR<-
							newRed.first -= dr[i];
							newRed.second -= dc[i];
						}
					}
				}
				else if (isFind) // R๋ง ๊ตฌ๋ฉ์ ๋น ์ง ๊ฒฝ์ฐ
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
```