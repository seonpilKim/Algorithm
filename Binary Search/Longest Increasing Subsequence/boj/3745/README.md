# [[3745] μ€λ¦μΈ](https://www.acmicpc.net/problem/3745)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <B>μκ³ λ¦¬μ¦ & μλ£κ΅¬μ‘°</B>
	- `LIS(Longest Increasing Subsequence)`
- <b>κ΅¬ν</b>
	- `LISμ κΈΈμ΄`λ₯Ό κ΅¬νκΈ° μν΄ μλ ₯ λ°μ μμ΄μ μμ°¨ νμνλ©΄μ μλμ μμμ μ§ννμλ€.
		- LIS λ°°μ΄μ΄ emptyμ΄κ±°λ, λ§¨ λ μμλ³΄λ€ ν¬λ€λ©΄, LIS λ°°μ΄μ νμ¬ μμ μ½μ
		- μμ λ κ²½μ°κ° λͺ¨λ μλλΌλ©΄, LIS λ°°μ΄μμ νμ¬ μμκ° λ€μ΄κ° μμΉλ₯Ό μ΄λΆ νμνμ¬ κ΅μ²΄
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main() {
	...

	while (cin >> N) {
		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		vector<int> LIS;
		for (int i = 0; i < N; i++) {
			int idx = lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
			if (LIS.empty() || LIS.back() < v[i])
				LIS.push_back(v[i]);
			else
				LIS[idx] = v[i];
		}
		cout << LIS.size() << '\n';
	}

	...
}
```