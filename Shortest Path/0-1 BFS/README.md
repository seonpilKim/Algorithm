# 0-1 BFS(Breadth First Search) ์๊ณ ๋ฆฌ์ฆ

## ๐๊ฐ๋
- `ํ ์ ์ ์์ ๋ชจ๋  ์ ์ `์ ๋ํ ์ต๋จ ๊ฑฐ๋ฆฌ๋ฅผ ๊ตฌํ๋ ์๊ณ ๋ฆฌ์ฆ์ด๋ค.
- `๊ฐ์  ๊ฐ์ค์น๊ฐ ๋ ์ข๋ฅ`๋ง ์กด์ฌํ  ๋ ์ฌ์ฉ ๊ฐ๋ฅํ๋ค.
    > ex) 0, 1
- ์๋ฃ๊ตฌ์กฐ `๋ฑ(deque)` ์ฌ์ฉ.
    - ๊ฐ์ค์น๊ฐ ๋ฎ์ผ๋ฉด ๋ฑ์ ์์ ๋ฃ๊ณ , ๊ฐ์ค์น๊ฐ ๋์ผ๋ฉด ๋ฑ์ ๋ค์ ๋ฃ๋๋ค.
    > <b>์ฐธ๊ณ </b> 
    > - `์ผ๋ฐ ํ(queue)`๋ฅผ ์ฌ์ฉํ๋ฉด, ์ฝ์๊ณผ ์ ๋ ฌ๋ ์ํ๋ฅผ ์ ์งํ๋ ๊ฒ์ O(1)์ ์ํํ์ง ๋ชปํ๋ค.
    > - `์ฐ์ ์์ ํ(priority queue)`๋ฅผ ์ฌ์ฉํ๋ฉด ์ ๋ ฌ๋ ์ํ๋ฅผ ์ ์งํ๋๋ฐ O(logโN)์ ์ํํ๋ฏ๋ก ๋นํจ์จ์ ์ด๋ค.
    > - `๋ฑ(deque)`์ ์ฌ์ฉํ๋ฉด, ์ ๋ ฌ๋ ์ํ๋ฅผ ์ ํ์๊ฐ์ ์ ์ง๊ฐ ๊ฐ๋ฅํ๋ค.
- <b>์๊ฐ ๋ณต์ก๋</b>
    - `O(E + V)`
## ๐ป๊ตฌํ
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