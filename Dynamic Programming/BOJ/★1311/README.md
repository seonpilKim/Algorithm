# [[1311] 할 일 정하기 1](https://www.acmicpc.net/problem/1311)

![](imgs/1.PNG)
![](imgs/2.PNG)

___
## 💡풀이
- <b>DFS</b>를 이용한 <b>Top-down 동적 계획법</b>을 이용하였다.
	- `dp[n][bitmask]`: 각 사람들에게 n개의 서로 다른 일을 각각 배정했을 때의 최소 비용
		- `bitmask`: 최대 20개의 bit를 이용하여 일을 배정받은 사람은 1, 그렇지 않으면 0으로 표현
	- Top-down 방식으로 구현 방식은 아래와 같다.
		- `Termination condition`: N명의 인원이 모두 일을 배정받은 경우, 즉 bitmask에서 N개의 bit가 모두 1인 경우, return 0
		- `Base condition`: dp 배열의 모든 값을 -1으로 초기화
		- `Memoization`: n개의 서로 다른 일이 최소 비용으로 먼저 배정된 경우, 즉 dp[n][bitmask] 값이 -1이 아닌 경우, 캐시에 저장된 값을 재활용.
		- `Recurrence relation`: dp[n][bitmask] = min(dp[n][bitmask], DFS(n + 1, bitmask | (1 << i)) + v[n][i])
	
___
## ✍ 피드백

___
## 💻 핵심 코드
```c++
int DFS(int n, int bitmask) {
	if (bitmask == (1 << N) - 1)
		return 0;
	if (dp[n][bitmask] != -1)
		return dp[n][bitmask];

	dp[n][bitmask] = MAX_COST;
	for (int i = 0; i < N; i++) {
		// 현재 경우에서 이미 i번째 사람이 일을 배정받았다면, continue
		if (bitmask & (1 << i))
			continue;
		
		// DFS(n + 1, bitmask | (1 << i)): n번째 일에 i번째 사람을 배정하고, n + 1번째 일을 처리
		// v[n][i]: n번째 일을 i번째 사람에게 배정했을 때의 비용
		dp[n][bitmask] = min(dp[n][bitmask], DFS(n + 1, bitmask | (1 << i)) + v[n][i]);
	}

	return dp[n][bitmask];
}
```