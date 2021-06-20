# 플로이드 와샬(Floyd Warshall) 알고리즘

## 📖개념
- `모든 정점 쌍`에 대해 둘 사이의 최단 거리를 구하는 알고리즘이다.
    - `경로가 거쳐가는 정점`을 기준으로 알고리즘을 수행한다.
        > 경유점을 지나서 가면, 거리가 단축되는가? 
- <b>점화식</b>
    ```c++
    weights[start][end] = min(weights[start][end], weights[start][mid] + weights[mid][end])
    ```
- <b>시간 복잡도</b>
    - `O(|V|³)`
- <b>공간 복잡도</b>
    - `O(|V|²)`
## 💻구현
```c++
int n; // 정점 개수
vector<vector<int>> weights(n, vector<int>(n)); // 정점 간 거리

for (int mid = 1; mid <= n; mid++) {
	for (int start = 1; start <= n; start++) {
        // 최적화. 간선이 적을 수록 효율적
		if (weights[start][mid] == MAX)
			continue;

		for (int end = 1; end <= n; end++) {
            // 사이클 회피
			if (start == end)
				continue;

			weights[start][end] = min(weights[start][end], weights[start][mid] + weights[mid][end]);
		}
	}
}
```