# [[2212] 센서](https://www.acmicpc.net/problem/2212)

## 🤔접근
- 고속도로 위에 N개의 센서가 주어지고(위치 중복 가능), K개의 집중국을 다음의 조건을 만족하면서 설치해야 한다.
	- 집중국 수신 가능 영역 길이의 합 최소화
	- 최소 수신 가능 영역 길이 0 이상
	- 모든 센서는 최소 하나의 집중국과 연결
- 즉, 각 센서들은 K개의 집중국 중 하나 이상의 수신 가능 범위에 속해야 하고, 이는 K개의 그룹을 만드는 것으로 생각할 수 있다.
	- 먼저 센서의 위치를 오름차순으로 정렬하고 각각 두 센서(i, i + 1번째)의 차이를 구하고 오름차순으로 정렬하자.
	- 다음으로 N - K개만큼 가장 작은 두 센서의 차이를 구하여 더해주면, 바로 각 집중국의 수신 가능영역의 거리의 합의 최솟값이 된다.
___
## 💡풀이
- <b>알고리즘 & 자료구조</b>
	- `Greedy`
- <b>구현</b>
	- 먼저 오름차순으로 정렬한 센서들의 중복 위치를 제거해준 다음, 각각 두 센서(i, i + 1)의 차이를 구하고 오름차순으로 정렬하였다.
	- 다음으로 가장 작은 N - K개의 값을 더해주었다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	sort(sensors.begin(), sensors.end());
	sensors.erase(unique(sensors.begin(), sensors.end()), sensors.end());

	N = sensors.size();
	vector<int> diff(N - 1);
	for (int i = 0; i < N - 1; i++) 
		diff[i] = sensors[i + 1] - sensors[i];
	sort(diff.begin(), diff.end());

	int ans = 0;
	for (int i = 0; i < N - K; i++) 
		ans += diff[i];

	...
}
```