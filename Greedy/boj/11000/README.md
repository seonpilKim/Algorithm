# [[11000] 강의실 배정](https://www.acmicpc.net/problem/11000)

## 🤔접근
- 수업 시작시간 -> 종료시간 오름차순으로 정렬한 배열과 최소 힙(우선순위 큐)을 이용해서 최소의 강의실 개수를 구해보자.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
	- `Greedy`
	- `Priority Queue`
- <b>구현</b>
	- 먼저 힙에 정렬한 수업 배열의 첫 번째 원소의 종료 시간을 저장하였다.
	- 정렬한 수업 배열을 순서대로 탐색하면서 아래의 작업을 수행하였다.
		- `힙의 top ≤ 현재 수업 시작시간` 이라면, 힙에 존재하는 원소를 pop하였다.
			- 현재 강의실을 그대로 사용할 수 있기 때문이다.
		- 힙에 `현재 수업 종료시간`을 저장하였다.
		- 매 번 최대 강의실 수를 갱신해주었다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int n, m;
		cin >> n >> m;
		v[i] = {n, m};
	}
	sort(v.begin(), v.end());

	priority_queue<int> pq;
	pq.push(-v.front().second);

	int ans = 1;
	for (int i = 1; i < N; i++) {
		while (!pq.empty() && -pq.top() <= v[i].first)
			pq.pop();
		pq.push(-v[i].second);
		ans = max(ans, (int)pq.size());
	}

	cout << ans;

	...
}
```