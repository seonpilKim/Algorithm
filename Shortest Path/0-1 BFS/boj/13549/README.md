# [[13549] μ¨λ°κΌ­μ§ 3](https://www.acmicpc.net/problem/13549)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>1μΉΈ μ΄λμ 1μ΄κ° μμλκ³ , μκ° μ΄λμ 0μ΄κ° μμλλ€.</b>
	- κ°μ€μΉκ° 1μΈ κ°μ κ³Ό 0μΈ κ°μ μ΄ μλ€κ³  μκ°νμ.
		- μ΄ κ²½μ°, λ€μ΅μ€νΈλΌλ³΄λ€ ν¨μ¬ ν¨μ¨μ μΈ 0-1 BFSλ₯Ό μ¬μ©νλ νΈμ΄ μ’λ€.
___
## π‘νμ΄
- <b>0-1 BFS μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ΄μ©νμλ€.
	- μκ°μ΄λ(κ°μ  κ°μ€μΉ 0)ν  λλ, λ°©λ¬Ένμ§ μμ μμΉμ΄λ©΄ λ±μ μμ push
	- ν μΉΈ μ΄λ(κ°μ  κ°μ€μΉ 1)ν  λλ, λ°©λ¬Ένμ§ μμ μμΉμ΄λ©΄ λ±μ λ€μ push
- μκ° λ³΅μ‘λ: `O(E + V)`
___
## β νΌλλ°±
1. <b>λ¨μ BFSλ μ¬μ©ν  μ μλ€.</b>
	- λ¨μ BFSλ `κ°μ  κ°μ€μΉκ° λͺ¨λ λμΌνκ±°λ μμ΄μΌ νλ€`λ μ μ μ‘°κ±΄μ΄ νμνλ€.
___
## π» ν΅μ¬ μ½λ
```c++
int BFS() {
	deque<pair<int, int>> q; // 0-1 BFSλ deque μ¬μ©
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