# [[2217] λ‘ν](https://www.acmicpc.net/problem/2217)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>νμ(Greedy) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- λ¬΄κ² μ€λ¦μ°¨μμΌλ‘ μ λ ¬νκ³ , μμ λ¬΄κ²μ λ‘νλ₯Ό νλμ© μ κ±°νλ©΄μ μ΅λ μ€λμ κ΅¬νμλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main(){
	...
	int ans = 0;
	sort(weight.begin(), weight.end(), greater<int>());
	while (!weight.empty()) {
		ans = max(ans, weight.back() * N--);
		weight.pop_back();
	}

	cout << ans;
	...
}
```