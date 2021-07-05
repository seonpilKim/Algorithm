# 에라토스테네스의 체(Sieve of Eratosthenes) 알고리즘

## 📖개념
- <b>`특정 숫자의 배수는 소수가 아니라는 법칙`에 착안하여, 2 ~ N 숫자에서 배수를 모두 제거한 뒤, 제거되지 않은 숫자를 소수로 판별하는 방식이다.</b>
	- 특정 범위에서의 모든 소수를 가장 빠르게 판별할 수 있는 알고리즘이다.
- <b>과정</b>
	- ![1](https://user-images.githubusercontent.com/68049320/124509385-d33e9580-de0c-11eb-9b43-40aa3fd03f88.gif)
	1. 2 ~ N까지의 모든 숫자를 나열한다.
	2. 2는 소수이므로 소수 배열에 담고, 2의 배수들을 모두 지운다.
	3. 다음으로 남아 있는 숫자인 3은 소수이므로 소수 배열에 담고, 3의 배수들을 모두 지운다.
	4. 위 과정을 N까지 반복한다.
- <b>시간 복잡도</b>
    - `O(N*log₂(log₂N))`
___
## 💻구현
```c++
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
