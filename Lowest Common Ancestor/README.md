# 최소 공통 조상(Lowest Common Ancestor) 알고리즘

## 💡 도입 배경
- 예를 들어 트리에서 임의의 두 노드를 선택하고, 두 노드의 최소 공통 조상을 찾으려면 어떻게 해야 할까?
	- 간단히 두 노드를 한 번씩 각자의 부모 노드로 올라가면서 찾을 수 있다.
		- 시간 복잡도: `O(N)`
	- 만약 트리에 노드가 무수히 많다고 할 때, 위의 작업을 여러 번 해야 한다면 어떨까?
		- 이미 지니간 경로들도 계속 확인해야 하므로, 매우 비효율적이다.
		- 시간 복잡도: `O(N * M)`
- 두 노드의 최소 공통 조상을 더 빠르게 찾을 수 있는 방법은 없을까?
## 📖 개념
- 현재 노드의 `2^i번째 부모 노드`를 저장하는 `희소 배열(Sparse table)`을 만들고, 이를 이용하여 두 노드의 최소 공통 조상을 찾는다.
	- `par[n][i] = 노드 번호가 n인 노드의 2^i번쨰 부모의 노드 번호`
- 현재 노드부터 1 -> 2 -> 4 -> 8... 번째 부모를 순차적으로 탐색하기 때문에, 기존의 방법보다 훨씬 빠르게 최소 공통 조상을 찾을 수 있다.
## 🕒 시간 복잡도
- `O(log₂N)`
## ⚙ 원리
![image](https://user-images.githubusercontent.com/68049320/151838381-89919176-f8dc-48cc-858c-13a3b1071a32.png)
- 먼저 각 `노드의 깊이(depth)`와 각 노드마다 `2^i 번쨰 부모 노드의 정보`를 저장해야 한다.
	- `DFS`를 이용하여 각 `노드의 깊이`를 구할 수 있다.
		- 이 과정에서 `2^0번째 부모`도 저장한다.
		```c++
		void DFS(int cur) {
		    for (int next : adj[cur]) {
		        if (depth[next] == -1) { // 방문 x인 경우
		            par[next][0] = cur;
		            depth[next] = depth[cur] + 1;
		            DFS(next);
		        }
		    }
		}
		```
	- 2중 for문을 이용하여 `각 노드의 2^i번째 부모`를 저장한다.
		```c++
		for (int h = 0; h < MAX - 1; h++) {
			 // root 부모는 설정할 필요가 없으므로, 2번 노드부터 설정
   		     for (int i = 2; i <= N; i++) { 
   		         int p = par[i][h];
   		         if (p != -1) // i번 노드의 2^h번째 부모가 존재하는 경우
   		             par[i][h + 1] = par[p][h];
   		     }
   		 }
		```
- 다음으로 두 노드의 깊이를 맞춰준 다음, 두 노드를 같이 부모로 올리면서 최소 공통 조상을 찾는다.
	```c++
	int LCA(int u, int v) {
	    if (depth[u] < depth[v])
	        swap(u, v);

	    int diff = depth[u] - depth[v];
	    int h = 0;
		// 먼저 두 노드의 깊이를 맞춘다.
	    while (diff) {
	        if (diff % 2)
	            u = par[u][h];
	        h++;
	        diff /= 2;
	    }

	    if (u != v) {
			// 예를 들어 11번째 부모라면, 8 -> 2 -> 1 순서대로 탐색해야 하므로, 내림차순으로 탐색
	        for (int h = MAX - 1; h >= 0; h--) {
				// 부모가 다른 경우, 해당 부모 노드로 갱신
	            if (par[u][h] != par[v][h]) {
	                u = par[u][h];
	                v = par[v][h];
	            }
	        }

			// 최소 공통 조상
	        return par[u][0];
	    }

		// 두 노드 중 하나가 부모인 경우
	    return u;
	}
	```
## 🤔 응용
- 주로 트리에서 `두 노드의 사이의 거리`, `두 노드의 경로 중 가중치가 가장 큰 간선` 구하기 등에서 사용된다.
## 💻구현 코드
```c++
int N, M;
vector<vector<int>> par, adj;
vector<int> depth;
const int MAX = 18; // 보통 log₂N + 2 정도로 설정

void DFS(int cur) {
    for (int next : adj[cur]) {
        if (depth[next] == -1) {
            par[next][0] = cur;
            depth[next] = depth[cur] + 1;
            DFS(next);
        }
    }
}

void init() {
    cin >> N;
    adj.resize(N + 1);
    depth.assign(N + 1, -1);
    par.assign(N + 1, vector<int>(MAX, -1));

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    DFS(1);
    for (int h = 0; h < MAX - 1; h++) {
        for (int i = 2; i <= N; i++) {
            int p = par[i][h];
            if (p != -1)
                par[i][h + 1] = par[p][h];
        }
    }

    cin >> M;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    int h = 0;
    while (diff) {
        if (diff % 2)
            u = par[u][h];
        h++;
        diff /= 2;
    }

    if (u != v) {
        for (int h = MAX - 1; h >= 0; h--) {
            if (par[u][h] != par[v][h]) {
                u = par[u][h];
                v = par[v][h];
            }
        }

        return par[u][0];
    }

    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}
```