# [[1946] μ μ μ¬μ](https://www.acmicpc.net/problem/1946)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>νμ(Greedy) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- μ§μμλ€μ μ±μ  μ€λ¦μ°¨μμΌλ‘ μ λ ¬νκ³ , ν­μ μ΄μ  μ§μμλ³΄λ€ 1μ°¨ μ±μ μ ν¬κ³ , 2μ°¨ μ±μ μ μμ μ§μμλ§ μ±μ©νλ©΄, μ‘°κ±΄μ λ§μ‘±νλ©΄μ μ΅λμΈμμΌλ‘ μ±μ©ν  μ μλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main(){
	...
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> applicant(N);
		for (int i = 0; i < N; i++)
			cin >> applicant[i].first >> applicant[i].second;
		sort(applicant.begin(), applicant.end());

		vector<pair<int, int>> selected;
		selected.push_back(applicant.front());
		for (int i = 1; i < N; i++) {
			if (applicant[i].first > selected.back().first && applicant[i].second < selected.back().second)
				selected.push_back(applicant[i]);
		}

		cout << selected.size() << '\n';
	}
	...
}
```