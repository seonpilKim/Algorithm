# [[2887] 행성 터널](https://www.acmicpc.net/problem/2887)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## 🤔접근
1. <b>MST를 구하는 크루스칼, 프림 알고리즘 모두 문제가 발생한다.</b>
	- 최대 정점: 10만개, 최대 간선: 5억개
	- 크루스칼(O(Elog₂E)): 메모리 초과, 시간 초과
	- 프림(O(V²)): 메모리 초과, 시간 초과
2. <b>간선의 수를 줄일 방법이 없을까?</b>
	- 각 정점간의 간선 가중치는 `min(x간 거리, y간 거리, z간 거리)`이다.
	- 각각 1차원(x, y, z)으로 정점을 세 종류로 나누어보자.
		- 여기서 1차원에서의 좌표들을 오름차순으로 정렬했을 때, 정렬된 상태 그대로 정점들을 1자로 연결하면 MST를 이룬다.
			- 예를들어, x좌표만 존재하는 1차원으로 보았을 때, 오름차순으로 정점을 정렬하여 1자로 쭉 연결하면 MST를 구할 수 있다. `(O(Vlog₂V))`
		- 이 아이디어를 이용해서, (i, i + 1)번째 정점끼리 x, y, z끼리 연결한 가중치들을 모두 모아 오름차순으로 정렬해보자. `(O(3Vlog₂3V))`
			- 이렇게 정렬된 상태에서 크루스칼 알고리즘을 이용하면 메모리 초과, 시간 초과 모두 해결할 수 있다.
			- 시간 복잡도: `O(Vlog₂V)`
			- 공간 복잡도: `O(V)`
___
## 💡풀이
- <b>크루스칼(Kruskal) 알고리즘</b>을(를) 사용하였다.
	1. 각각 X, Y, Z 배열에 i번째 정점의 좌표와 정점의 번호를 저장한다.
	2. X, Y, Z 배열을 좌표 오름차순으로 정렬한다.
	3. 각 (i, i + 1) 정점끼리 각각 x, y, z좌표끼리 연결한 간선들을 edges 배열에 (가중치, 시작 정점, 도착 정점)으로 저장한다.
	4. edges 배열을 가중치 오름차순으로 정렬한다.
	5. union-find 함수를 이용하여 사이클 유뮤를 체크하며, N - 1개의 간선을 갖는 MST를 구한다.
___
## ✍ 피드백
1. <b>정점들이 1차원에 놓여져 있을 때, 정점들을 좌표 오름차순으로 정렬하고 1자로 연결하면 MST를 이룬다는 것을 기억하자.</b>
___
## 💻 핵심 코드
```c++
int main(){
	...
	for (int i = 0; i < V; i++) {
		cin >> x >> y >> z;
		X[i] = make_pair(x, i);
		Y[i] = make_pair(y, i);
		Z[i] = make_pair(z, i);
		par[i] = i;
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	cout << kruskal();
	...
}

int kruskal() {
	int res = 0;
	vector<pair<int, pair<int, int>>> edges(3 * (V - 1));

	for (int i = 0, idx = 0; i < V - 1; i++, idx += 3) {
		edges[idx] = make_pair(X[i + 1].first - X[i].first, make_pair(X[i].second, X[i + 1].second));
		edges[idx + 1] = make_pair(Y[i + 1].first - Y[i].first, make_pair(Y[i].second, Y[i + 1].second));
		edges[idx + 2] = make_pair(Z[i + 1].first - Z[i].first, make_pair(Z[i].second, Z[i + 1].second));
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int weight = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		if (find(u) == find(v))
			continue;

		merge(u, v);
		res += weight;
	}
	return res;
}
```