# [[1011] Fly me to the Alpha Centauri](https://www.acmicpc.net/problem/1011)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>νμ(Greedy) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- λ μ§μ κ°μ μ°¨μ΄(dist)λ§νΌ μ΄λν΄μΌ νλ€.
	- kκ΄λμ μ΄λνλ©΄ k-1, k, k+1 κ΄λλ§νΌ μ΄λμ΄ κ°λ₯νλ€.
		- κ°μ₯ μ΅μλ‘ μ΄λ μ₯μΉλ₯Ό μλνλ €λ©΄, κ²°κ΅­ `1 2 ... N-1 N N-1 ... 2 1` μ΄μ κ°μ΄ μ΄λν΄μΌ νλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main(){
	...
	for (int i = 0; i < N; i++) {
		long long dist = v[i].second - v[i].first; // λ μ§μ  κ±°λ¦¬ μ°¨
		int ans = 0;

		long long n = 1;
		long long cur = 0;
		while (true) {
			if (cur + 2 * n <= dist) { // Nμ μ μΈν μ λ(1, 2, ... N-1)
				cur += 2 * n++;
				ans += 2;
			}
			else if (cur + n <= dist) { // N
				cur += n;
				ans++;
			}
			else
				break;
		}
		dist -= cur;

		while (dist) { // 1 2 .. N-1 N N N N-1 ... 2 1 λ°©μ§
			if (dist < n)
				n--;
			else {
				dist -= n;
				ans++;
			}
		}

		cout << ans << '\n';
	}
	...
}
```