# [[13164] 행복 유치원](https://www.acmicpc.net/problem/13164)

## 🤔접근
- `같은 조에 속한 원생간의 키 차이가 최소`여야만 K개의 조에 티셔츠를 만드는 비용이 최소임에 주목하였다.
	- 먼저, `인접한 두 원생의 키 차이`를 구하고 오름차순으로 정렬하였다. (총 N - 1개)
	- 인접한 두 원생의 키 차이가 `가장 작은 것 부터 N - K개를 선택`해서 그룹핑해주면, `같은 조에 속한 원생간의 키 차이가 최소`인 K개의 조를 만들게 된다.
		> 1번 그룹핑하면 N - 1개의 조가 만들어지고, 2번 그룹핑하면 N - 2개의 조가 만들어지는 방식
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
	- `Greedy`
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	int N, K;
	cin >> N >> K;
	vector<int> dist(N - 1);
	
	int cur, prev;
	cin >> prev;
	for (int i = 0; i < N - 1; i++) {
		cin >> cur;
		dist[i] = cur - prev;
		prev = cur;
	}
	sort(dist.begin(), dist.end());

	int ans = 0;
	for (int i = 0; i < N - K; i++)
		ans += dist[i];
	cout << ans;

	...
}
```