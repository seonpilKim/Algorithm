# [[11657] ํ์๋จธ์ ](https://www.acmicpc.net/problem/11657)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
- ์์ ๊ฐ์ค์น๊ฐ ์กด์ฌํ๋ ์ต์ ๊ฒฝ๋ก ์ฐพ๊ธฐ ๋ฌธ์ ์ด๋ค.
	- ํ๋ก์ด๋-์์ฌ ์๊ณ ๋ฆฌ์ฆ์ O(Vยณ)์ด๋ฏ๋ก ์๊ฐ์ด๊ณผ, ๋ฐ๋ผ์ ๋ฒจ๋ง-ํฌ๋ ์๊ณ ๋ฆฌ์ฆ(O(V*E))์ ์ฌ์ฉํ์.
___
## ๐กํ์ด
- <b>์๊ณ ๋ฆฌ์ฆ & ์๋ฃ๊ตฌ์กฐ</b>
	- `Bellman-Ford`
- <b>๊ตฌํ</b>
	- for๋ฌธ์ ํ ๋ฒ ๋ ๋๋ฆผ์ผ๋ก์จ, ์์ ์ธ์ดํด์ด ๋ฐ์ํ๋์ง ํ๋จํ  ์ ์๋ค.
___
## โ ํผ๋๋ฐฑ
- 500 * 6000 * 10000์ intํ ๋ฒ์๋ฅผ ๋ฒ์ด๋๋ฏ๋ก, long longํ์ ์ด์ฉํด์ผ ํ๋ค.
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
bool bellman_ford(const vector<vector<pair<int, int>>> adj, vector<long long>& dist, const int& start) {
	bool isNegativeCycle = false;
	int n = dist.size();
	dist[start] = 0;

	for (int i = 1; i < n; i++) {
		for (int cur = 1; cur < n; cur++) {
			if (dist[cur] == INF)
				continue;

			for (auto next : adj[cur]) {
				if (dist[next.first] > dist[cur] + next.second) {
					dist[next.first] = dist[cur] + next.second;
					if (i == n - 1)
						isNegativeCycle = true;
				}
			}
		}
	}

	return isNegativeCycle;
}

int main() {
	...

	if (bellman_ford(adj, dist, 1))
		cout << -1;
	else 
		for (int i = 2; i <= N; i++)
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';

	...
} 
```