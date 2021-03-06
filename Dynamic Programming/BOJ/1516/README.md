# [[1516] κ²μ κ°λ°](https://www.acmicpc.net/problem/1516)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>μμ μ λ ¬μ μ μ΄μ©νλ©΄, κ° κ±΄λ¬Όμ μμλλ‘ κ±΄μ€ν  μ μμΌλ―λ‘ μ΅μ μκ°μΌλ‘ κ±΄λ¬Όμ μμ±μν¬ μ μλ€.</b>
2. <b>λμ  κ³νλ²μ μ΄μ©νμ¬, μ΄μ  κ±΄λ¬ΌκΉμ§ μμλλ μ΅μ μκ° μ λ³΄λ₯Ό μ΄μ©νμ¬ νμ¬ κ±΄λ¬ΌκΉμ§ μμλλ μκ°μ κ΅¬νμ.</b>
___
## π‘νμ΄
- <B>μκ³ λ¦¬μ¦ & μλ£κ΅¬μ‘°</B>
	- `Topological Sort`
	- `DP`
- <b>κ΅¬ν</b>
	- μμ μ λ ¬ μκ³ λ¦¬μ¦μ λμ  κ³νλ²μ μμ©νμ¬ ν΄κ²°νμλ€.
		- `νμ¬ κ±΄λ¬Όμ΄ μμ±λκΈ°κΉμ§ κ±Έλ¦¬λ μ΅μ μκ°`λ³΄λ€ (`μ΄μ  κ±΄λ¬Όμ΄ μμ±λκΈ°κΉμ§ κ±Έλ¦¬λ μ΅μ μκ°` + `νμ¬ κ±΄λ¬Όμ μ§λλ° κ±Έλ¦¬λ μκ°`)μ΄ ν¬λ€λ©΄, κ°±μ ν΄μ£Όμλ€.
		- μ νμ
			- `result[next] = max(result[next], result[cur] + time[next])`
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
bool topologicalSort(const vector<vector<int>>& adj, vector<int>& inDegree, const int& N, vector<int>& result) {
    queue<int> q;
    vector<int> time(N + 1);

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
        time[i] = result[i];
    }

    for (int u = 1; u <= N; u++) {
        if (q.empty())
            return false;

        int cur = q.front();
        q.pop();
 
        for (int next : adj[cur]) {
            if (--inDegree[next] == 0) 
                q.push(next);
            result[next] = max(result[next], result[cur] + time[next]);
        }
    }

    return true;
}
```