# [[11726] 2×n 타일링](https://www.acmicpc.net/problem/11726)

![](imgs/1.PNG)
___
## 🤔접근
___
## 💡풀이
- <B>알고리즘 & 자료구조</B>
    - `DP - Tilling`
- <b>구현</b>
	- `1열과 2열을 채우는 방식`은 아래와 같다.<br>
		![](imgs/2.PNG)
		- <b>기저 조건:</b>
			- `dp[0] = 1`
			- `dp[1] = 1`
			- `dp[2] = 2`
	- <b>점화식</b>
		```c++
		for (int i = 3; i <= N; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]);
		```
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
    ...

    dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[N];

    ...
}
```