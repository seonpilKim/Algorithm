# [[12852] 1λ‘ λ§λ€κΈ° 2](https://www.acmicpc.net/problem/12852)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>Nμ 1λ‘ λ§λ€ μ μλ λ°©λ²μ 3κ°μ§λ‘ μ£Όμ΄μ‘λ€.</b>
	- BFS λλ DPλ‘ ν΄κ²°ν  μ μλ€.
2. <b>μΆκ°λ‘ Nμ 1λ‘ λ§λλ λ°©λ²μ ν¬ν¨λμ΄ μλ μλ₯Ό μΆλ ₯ν΄μΌ νλ€.</b>
	- νμ¬ μ μ Xμμ λ€μ μ μ Yλ‘ κ° λ, Yμ λν΄ μ΄μ  μ μ κ°μΈ Xλ₯Ό μ μ₯νλ λ°°μ΄μ λ§λ€μ.
___
## π‘νμ΄
- <b>Top-bottom λμ κ³νλ² μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
__
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int DFS(int num) {
	if (num == 1)
		return 0;
	if (dp[num])
		return dp[num];

	int res[3] = {MAX, MAX, MAX};
	if (num % 3 == 0)
		res[0] = DFS(num / 3) + 1;
	if (num % 2 == 0)
		res[1] = DFS(num / 2) + 1;
	res[2] = DFS(num - 1) + 1;

	int minimum = min({res[0], res[1], res[2]});
	if (minimum == res[0])
		before[num] = num / 3;
	else if (minimum == res[1])
		before[num] = num / 2;
	else if (minimum == res[2])
		before[num] = num - 1;
	return dp[num] = minimum;
}
```