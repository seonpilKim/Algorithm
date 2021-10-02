# [[2467] 용액](https://www.acmicpc.net/problem/2467)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## 🤔접근
1. <b>음수만 있는 경우, 양수만 있는 경우, 음수와 양수가 섞인 경우로 나누자.</b>
	- 음수만 있는 경우에는 가장 큰 두 값을 더한 것이 가장 0에 가깝다.
	- 양수만 있는 경우에는 가장 작은 두 값을 더한 것이 가장 0에 가깝다.
	- 음수와 양수가 섞인 경우에는 두 수 합의 절댓값이 작을수록 0에 가깝다.
2. <b>각 수마다 다른 수끼리 모두 더해보면서 최적의 값을 구하자.</b>
	- 단순히 완전 탐색을 하면 O(N²)으로 TLE이다.
	- O(NlogN) 이하로 구할 수 있는 방법은 없을까? -> 이분탐색!
___
## 💡풀이
- <B>이분 탐색(Binary Search) 알고리즘</B>을(를) 사용하였다.
	- 음수만 존재하거나, 양수만 존재하는 경우 O(1)으로 구할 수 있다.
		- 음수만 존재: v[last - 1], v[last]
		- 양수만 존재: v[first], v[first + 1]
	- 음수와 양수가 모두 존재하는 경우, 이분 탐색으로 최적의 값을 구하자.
		- N개의 수를 각각 한 번씩 선택(i)하고, i + 1부터 마지막 값까지 이분 탐색을 진행하자.
		- 선택한 값과 이분 탐색으로 찾은 값을 더했을 때, 아래와 같이 탐색 범위를 좁혀나가자.
			- 두 수를 더한 값이 `양수`: high = mid - 1
			- 두 수를 더한 값이 `음수`: low = mid + 1
		- 탐색 범위를 좁힌 다음, 두 수를 더한 값의 절댓값이 가장 최솟값이라면 갱신하자.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	if (hasNegative && hasPositive) { // Negative + Positive
		for (int i = 0; i < N - 1; i++) {
			int low = i + 1, high = N - 1;
			int mid, cur = v[i], target;
			while (low <= high) {
				mid = (low + high) / 2;
				target = v[mid];

				if (cur + target > 0)
					high = mid - 1;
				else
					low = mid + 1;

				if (minSum > abs(cur + target)) {
					minSum = abs(cur + target);
					idx[0] = i;
					idx[1] = mid;
				}
			}
		}
	}
	else if (hasNegative) { // only Negative
		idx[0] = N - 2;
		idx[1] = N - 1;
	}
	else if (hasPositive) { // only Positive
		idx[0] = 0;
		idx[1] = 1;
	}

	...
}
```