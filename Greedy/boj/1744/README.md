# [[1744] μ λ¬ΆκΈ°](https://www.acmicpc.net/problem/1744)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>νμ(Greedy) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- μμλ λ΄λ¦Όμ°¨μμΌλ‘ μ λ ¬νμ¬, ν° μλΌλ¦¬ κ³±νμ¬ λνλ€.
		- 1μ κ³±νλ κ² λ³΄λ€, λνλ κ²μ΄ μ’μΌλ―λ‘ μ£Όμνμ.
	- μμλ μ€λ¦μ°¨μμΌλ‘ μ λ ¬νμ¬, μμ μλΌλ¦¬ κ³±νμ¬ λνλ€.
		- λ§μ½ μλ ₯μ 0μ΄ μλ€λ©΄, λ§μ§λ§ λ¨μ μμμ κ³±νμ¬ μμμν€μ.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main(){
	...
for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n > 0)
			pos.push(n);
		else if (n < 0)
			neg.push(n);
		else
			zero++;
	}

	long long ans = 0;
	if (!pos.empty()) {
		while (pos.size() > 1) {
			if (pos.top() == 1)
				break;

			long long n = pos.top(); pos.pop();
			if (pos.top() == 1) {
				ans += n + 1;
				pos.pop();
				continue;
			}

			long long m = pos.top(); pos.pop();
			ans += n * m;
		}

		while (!pos.empty()) { // 1μ λͺ¨λ λν¨
			ans += pos.top();
			pos.pop();
		}
	}

	if (!neg.empty()) {
		while (neg.size() > 1) {
			long long n = neg.top(); neg.pop();
			long long m = neg.top(); neg.pop();
			ans += n * m;
		}

		if (!zero && !neg.empty()) // 0μΌλ‘ μμλ₯Ό μμ
			ans += neg.top();
	}

	cout << ans;
	...
}
```