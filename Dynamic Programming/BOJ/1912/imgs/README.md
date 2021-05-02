## [[1912] 연속합](https://www.acmicpc.net/problem/1912)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## 💡풀이
- 동적계획법을 이용하였다.
- Bottom-up 방식으로 구현하였다.
	- 숫자를 하나씩 입력받으면서, `현재 입력값 + 이전 입력값`이 `0 이상`이면 `dp[현재 인덱스]`에 `더한 값`을 저장하고, `음수`이면 `현재 입력값만` 저장한다.
```c++
// Base condition
dp[0] = max = num;

// Bottom-up
for (int i = 1; i < N; i++) {
    cin >> num;
    if (dp[i - 1] >= 0)
        dp[i] = dp[i - 1] + num;
    else
        dp[i] = num;
    if (max < dp[i])
        max = dp[i];
}

cout << max;
```