# [[12851] μ¨λ°κΌ­μ§ 2](https://www.acmicpc.net/problem/12851)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>κ±·κ±°λ μκ°μ΄λν΄μ λμμ μμΉλ₯Ό μ°Ύλ λ¬Έμ </b>
	- λ μ΄λ μλ¨ λͺ¨λ 1μ΄λ‘ λμΌνλ―λ‘, κ°μ μ κ°μ€μΉκ° λͺ¨λ λμΌν  λ μ΅λ¨κ²½λ‘λ₯Ό μ°Ύλ BFS μκ³ λ¦¬μ¦μ μ΄μ©νμ.
2. <b>λμμ μ°Ύλ κ°μ₯ λΉ λ₯Έ μκ°κ³Ό, κ·Έ λ°©λ²μ μλ₯Ό κ΅¬ν΄μΌ νλ€.</b>
	- κ° μμΉλ³λ‘ κ°μ₯ λΉ λ₯΄κ² λμ°©νλ μκ°μ μ μ₯νκ³ , λμμ μμΉμ λλ¬νλ©΄ μΉ΄μ΄ννμ.
___
## π‘νμ΄
- <b>λμ΄ μ°μ  νμ(BFS) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
// BFS
while (!next.empty()) {
	while (!next.empty()) {
		cur.push(next.front());
		dp[next.front()] = time;
		next.pop();
	}

	while (!cur.empty()) {
		int loc = cur.front();
		cur.pop();
		
		if (loc == K) {
			cnt++;
			continue;
		}
		if (loc > 0 && dp[loc - 1] > time)
			next.push(loc - 1);
		if (loc < 100000 && dp[loc + 1] > time)
			next.push(loc + 1);
		if (2 * loc <= 100000 && dp[2 * loc] > time)
			next.push(2 * loc);
	}
	time++;
}
```