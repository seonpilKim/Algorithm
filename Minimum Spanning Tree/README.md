# [[1644] 소수의 연속합](https://www.acmicpc.net/problem/1644)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## 🤔접근
1. <b>1 ~ N 사이의 소수들을 모두 구하자.</b>
	- 에라토스테네스의 체 알고리즘으로 구하자.
2. <b>위에서 구한 소수 수열의 연속된 부분합으로 N을 표현할 수 있는 경우의 수를 구하자.</b>
	- 투 포인터 알고리즘을 이용하여 연속된 부분합이 N인 경우의 수를 O(N)에 구하자.
	___
## 💡풀이
- <b>에라토스테네스의 체, 투 포인터(Two-Pointers) 알고리즘</b>을(를) 사용하였다.
__
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main(){
	...

	vector<int> primes = SieveOfEratosthenes();
	vector<int> sum(primes.size() + 1);
	for (int i = 1; i <= primes.size(); i++)
		sum[i] = sum[i - 1] + primes[i - 1];

	int cnt = 0;
	int first = 1, last = 1;
	while (first <= last && last <= primes.size()) {
		if (last <= primes.size() && sum[last] - sum[first - 1] >= N) {
			if (sum[last] - sum[first - 1] == N)
				cnt++;
			first++;
		}
		else
			last++;
	}

	...
}
vector<int> SieveOfEratosthenes() {
	vector<bool> numbers(N + 1, true);
	vector<int> primes;

	for (int i = 2; i <= N; i++) {
		if (!numbers[i])
			continue;

		for (int j = 2 * i; j <= N; j += i)
			numbers[j] = false;
	}

	for (int i = 2; i <= N; i++)
		if (numbers[i])
			primes.push_back(i);

	return primes;
}
```