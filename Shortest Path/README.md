# 최단 경로(Shortest Path) 알고리즘

## 📚종류
- BFS
- 다익스트라(Dijkstra)
- 벨만포드(Bellman Ford)
- [플로이드 와샬(Floyd Warshall)](https://github.com/seonpilKim/Algorithm/tree/master/Shortest%20Path/Floyd%20Warshall)
___
## 📊비교
- 공통적으로 그래프에 <span style="color:yellow">음의 사이클❌</span>이어야 한다.

<table>
<tr>
<th>BFS</th>
<th>다익스트라</th>
<th>벨만 포드</th>
<th>플로이드 와샬</th>
</tr>
<tr>
<td>가중치❌ 그래프</td>
<td>가중치⭕ 그래프</td>
<td>가중치⭕ 그래프</td>
<td>가중치⭕ 그래프</td>
</tr>
<tr>
<td>가중치❌</td>
<td>가중치가 <b>양의 정수</b>일 때만 가능</td>
<td>가중치가 <b>음의 정수</b>일 때도 가능</td>
<td>가중치가 <b>음의 정수</b>일 때도 가능</td>
</tr>
<tr>
<td><b>큐</b> 사용</td>
<td><b>우선순위 큐</b> 사용</td>
<td>동적계획법(DP) 방식<br><b>distance[n] = min(distance[n], distance[m] + E(m, n))</b></td>
<td>동적계획법(DP) 방식<br><b>distance[start][end] = min(distance[start][end], distance[start][mid] + distance[mid][end])</b></td>
</tr>
<tr>
<td>시간복잡도: <b>O(E)</b></td>
<td>시간복잡도: <b>O(E*logV)</b></td>
<td>시간복잡도: <b>O(V*E)</b></td>
<td>시간복잡도: <b>O(V³)</b></td>
</tr>
<tr>
<td>하나의 특정 정점에서 다른 정점들까지의 최단 경로를 구함<br><b>1 : N</b></td>
<td>하나의 특정 정점에서 다른 정점들까지의 최단 경로를 구함<br><b>1 : N</b></td>
<td>하나의 특정 정점에서 다른 정점들까지의 최단 경로를 구함<br><b>1 : N</b></td>
<td>모든 정점들간의 쌍에 대해 최단 경로를 한번에 구함<br><b>N : N</b></td>
</tr>
</table>