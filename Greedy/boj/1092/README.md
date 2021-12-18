# [[1092] 배](https://www.acmicpc.net/problem/1092)

## 🤔접근
- 각 크레인이 최대로 들 수 있는 무게에 가장 가까운 무게의 박스를 우선적으로 이동시켜야, 가능한 많은 크레인을 활용할 수 있다.
- M이 최대 10,000개 이므로, `이분 탐색`을 이용하여 위의 조건에 해당하는 무게를 찾아보자.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
	- `Greedy`
	- `Binary Search`
- <b>구현</b>
	- 먼저 이분 탐색을 위해 박스 배열을 무게 오름차순으로 정렬하였다.
		- 만약 가장 무거운 무게를 들 수 있는 크레인이 가장 무거운 박스를 옮길 수 없다면, -1을 출력하고 종료한다.
	- 옮길 박스가 없을 때 까지 아래의 작업을 반복하였다.
		- 각 크레인마다 이분 탐색으로 해당 크레인이 들 수 있는 최대 무게보다 작으면서 가장 가까운 무게의 박스를 찾고, 이를 boxes 배열에서 지워주었다.
		- 이 때, `upper_bound` 함수를 사용했으며, 만약 반환된 iterator가 begin이라면, 해당 크레인으로는 옮길 수 있는 박스가 없다는 뜻이다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {

	...
	sort(cranes.begin(), cranes.end(), greater<int>());
	
	...
	sort(boxes.begin(), boxes.end());
	
	if (boxes.back() > cranes.front()) 
		cout << -1;
	else {
		int ans = 0;
		while (!boxes.empty()) {
			ans++;
			for (auto crane : cranes) {
				auto iter = upper_bound(boxes.begin(), boxes.end(), crane);
				if (iter != boxes.begin())
					boxes.erase(--iter);
			}
		}
		cout << ans;
	}

	...
}
```