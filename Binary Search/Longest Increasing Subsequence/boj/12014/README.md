# [[12014] 책정리](https://www.acmicpc.net/problem/12014)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## 🤔접근
1. <b>주가가 오를 때만 사는 방법은 LIS를 구하는 방법으로 구할 수 있다.</b>
	- LIS의 길이가 K 이상이라면, 조건을 만족하게 주식을 구입할 수 있다.
___
## 💡풀이
- <B>알고리즘 & 자료구조</B>
	- `LIS(Longest Increasing Subsequence)`
- <b>구현</b>
	- `LIS의 길이`를 구하기 위해 입력 받은 수열을 순차 탐색하면서 아래의 작업을 진행하였다.
		- LIS 배열이 empty이거나, 맨 끝 원소보다 크다면, LIS 배열에 현재 원소 삽입
		- 위의 두 경우가 모두 아니라면, LIS 배열에서 현재 원소가 들어갈 위치를 이분 탐색하여 교체
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	for (int t = 1; t <= T; t++) {
		int N, K;
		cin >> N >> K;

		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];

		vector<int> LIS;
		for (int i = 0; i < N; i++) {
			if (LIS.empty() || LIS.back() < v[i])
				LIS.push_back(v[i]);
			else {
				int idx = lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
				LIS[idx] = v[i];
			}
		}
		cout << "Case #" << t << '\n';
		if (LIS.size() >= K)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	...
}
```