# [[11047] λμ  0](https://www.acmicpc.net/problem/11047)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>νμ(Greedy) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- ν° λμ λΆν° μμ λμ  μμλ‘ λ¨Όμ  μ¬μ©νλ©΄ μ΅μμ λμ μ μ¬μ©ν΄μ κ·Έ ν©μ Kλ‘ λ§λ€ μ μλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main(){
	...
	sort(coin.begin(), coin.end(), less<int>());

	int ans = 0;
	int cur = 0;
	int idx = coin.size() - 1;

	while (cur != K) {
		if (coin[idx] > K - cur)
			idx--;
		else {
			cur += coin[idx];
			ans++;
		}
	}

	cout << ans;
	...
}
```