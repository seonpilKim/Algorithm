# [[2252] μ€ μΈμ°κΈ°](https://www.acmicpc.net/problem/2252)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>μΌλΆ νμλ€μ λ νμμ ν€λ₯Ό λΉκ΅ν μ λ³΄λ₯Ό ν΅νμ¬ νμλ€μ ν€ μμλλ‘ μ€μ μΈμμΌ νλ€.</b>
	- μλ ₯μΌλ‘ μ£Όμ΄μ§ ν€ μμλλ‘ νμλ€μ μ λ ¬ν΄μΌ νλ€.
	- μμ μ λ ¬ μκ³ λ¦¬μ¦μ μ΄μ©νμ.
___
## π‘νμ΄
- <b>μμ μ λ ¬(Topological Sort) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
__
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
for (int i = 0; i < M; i++) {
	cin >> n1 >> n2;
	people[n1].push_back(n2);
	degree[n2]++;
}

queue<int> q;
for (int i = 1; i <= N; i++)
	if (degree[i] == 0)
		q.push(i);

while(!q.empty()) {
	int cur = q.front();
	q.pop();
	cout << cur << ' ';
	for (int i = 0; i < people[cur].size(); i++) {
		int next = people[cur][i];
		if (--degree[next] == 0)
			q.push(next);
	}
}
```