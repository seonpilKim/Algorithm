# 0-1 BFS(Breadth First Search) 알고리즘

## 📖개념
- `한 정점에서 모든 정점`에 대한 최단 거리를 구하는 알고리즘이다.
- `간선 가중치가 두 종류`만 존재할 때 사용 가능하다.
    > ex) 0, 1
- 자료구조 `덱(deque)` 사용.
    - 가중치가 낮으면 덱의 앞에 넣고, 가중치가 높으면 덱의 뒤에 넣는다.
    > <b>참고</b> 
    > - `일반 큐(queue)`를 사용하면, 삽입과 정렬된 상태를 유지하는 것을 O(1)에 수행하지 못한다.
    > - `우선순위 큐(priority queue)`를 사용하면 정렬된 상태를 유지하는데 O(log₂N)에 수행하므로 비효율적이다.
    > - `덱(deque)`을 사용하면, 정렬된 상태를 선형시간에 유지가 가능하다.
- <b>시간 복잡도</b>
    - `O(E + V)`
## 💻구현
```c++
int BFS() {
	deque<pair<int, int>> q;
	q.emplace_back(0, N);
	visited[N] = true;

	while (!q.empty()) {
		auto p = q.front(); q.pop_front();
		int seconds = p.first;
		int location = p.second;
		
		if (location == K)
			return seconds;

		if (location * 2 < MAX && !visited[location * 2]) {
			q.emplace_front(seconds, location * 2);
			visited[location * 2] = true;
		}
		if (location + 1 < MAX && !visited[location + 1]) {
			q.emplace_back(seconds + 1, location + 1);
			visited[location + 1] = true;
		}
		if (location - 1 >= 0 && !visited[location - 1]) {
			q.emplace_back(seconds + 1, location - 1);
			visited[location - 1] = true;
		}
	}
}
```