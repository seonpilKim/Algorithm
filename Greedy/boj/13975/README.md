# [[13975] 파일 합치기 3](https://www.acmicpc.net/problem/13975)

## 🤔접근
- 합친 파일들은 계속 합쳐지는 데 사용되기 때문에, 가능한 가장 작은 파일들을 먼저 합치는 게 중요하다.
	- 만약, 큰 파일을 처음부터 합치기 시작하면, 큰 파일의 크기를 계속 덧셈하는 격이므로 당연히 최소비용을 구할 수 없다.
	- 요약하자면, 하나의 파일을 만들기 위해서는 어차피 각각의 파일은 여러 번 합쳐질 수 밖에 없다, 따라서 가능한 가장 크기가 작은 파일들을 여러 번 합치는 것이 최적의 해이다.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
	- `Greedy`
	- `Priority Queue`
- <b>구현</b>
	- 우선순위 큐(최소 힙)에 하나만 남을 때 까지, 두 개씩 빼내어 더한 값을 다시 우선순위 큐에 넣어주었다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	priority_queue<long long> pq;
		for (int i = 0; i < N; i++) {
			long long n;
			cin >> n;
			pq.push(-n);
		}

		long long ans = 0;
		while (pq.size() > 1) {
			long long sum = -pq.top(); pq.pop();
			sum += -pq.top(); pq.pop();
			ans += sum;
			pq.push(-sum);
		}

	...
}
```