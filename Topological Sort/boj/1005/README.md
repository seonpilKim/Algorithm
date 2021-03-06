# [[1005] ACM Craft](https://www.acmicpc.net/problem/1005)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>μ£Όμ΄μ§ μ ν κ±΄μ€ μ λ³΄λ₯Ό ν λλ‘, μ μ²΄μ μΈ κ±΄μ€ μμλ₯Ό κ΅¬νμ.</b>
	- μμ μ λ ¬ μκ³ λ¦¬μ¦μ μ΄μ©νμ.
2. <b>μ ν κ±΄μ€μ΄ λ κ° μ΄μμΈ κ²½μ°, λ μ€ λ μ€λ κ±Έλ¦¬λ μκ°μ΄ μ§λμΌ νλ€.</b>
	- λμ κ³νλ²μ μ΄μ©νμ.
	- `λ€μ κ±΄μ€ μκ°`κ³Ό `(νμ¬κΉμ§μ κ±΄μ€ μκ°μ λν κ° + λ€μ κ±΄μ€ μκ°)` μ€ ν° κ°μ λ€μκΉμ§μ κ±΄μ€ μκ°μ μ μ₯νμ.
___
## π‘νμ΄
- <b>μμ μ λ ¬(Topological Sort), λμ κ³νλ²(DP) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
__
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
while (T--) {
	cin >> N >> K;

	vector<int> dp(N + 1);
	vector<int> delay(N + 1);
	vector<int> inDegree(N + 1);
	vector<vector<int>> adj(N + 1, vector<int>());

	for (int i = 1; i <= N; i++)
		cin >> delay[i];

	int n1, n2;
	for (int i = 0; i < K; i++) {
		cin >> n1 >> n2;
		adj[n1].push_back(n2);
		inDegree[n2]++;
	}

	int number;
	cin >> number;

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
		dp[i] = delay[i]; // μ ν κ±΄μ€μ΄ μλ κ²½μ°λ₯Ό μν΄
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			dp[next] = max(dp[next], dp[cur] + delay[next]);
			if (--inDegree[next] == 0) 
				q.push(next);
		}
	}

	result.push_back(dp[number]);
}
```