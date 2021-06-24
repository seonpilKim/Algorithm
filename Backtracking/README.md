# 백트래킹(Backtracking) 알고리즘

## 📖개념
- 기본적으로 `재귀적`으로 문제를 하나씩 해결하는 방식이다.
- 각 재귀에서 `현재 상태(노드)가 제한 조건을 만족하는지(유망한지) 판단`하고, 해당 경우 `현재 상태(노드)를 제외`하고 `다음 단계`로 나아가는 방식이다.
- 여기서 `유망(promising)하지 않은 상태를 제외`하는 것을 `가지치기(pruning)`이라고 한다.
	- 유망하지 않은 상태라고 결정되면, `이전 상태로 돌아가(backtracking)` 다음 상태를 체크한다.
- 즉, 이 방법을 통해 모든 경우의 수를 체크하지 않고, `필요한 경우만 체크`함으로써 완전탐색에 비해 `시간복잡도를 크게 향상`시킬 수 있다.
- 백트래킹 알고리즘은 주로 `DFS`를 사용하여 구현한다.

### DFS와 Backtracking 차이
- <b>DFS</b>: 완전 탐색을 기본으로 하는 그래프 순회 기법으로, `모든 노드를 방문`하는 것을 목표로 한다.
- <b>Backtracking</b>: 불필요한 탐색은 하지 않으며, `이전 단계로 돌아와 다른 후보해를 탐색`해 나가는 방법으로, `유망하지 않은 경우의 수를 줄이는 것`을 목표로 한다.