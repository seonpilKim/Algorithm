# [[1339] λ¨μ΄ μν](https://www.acmicpc.net/problem/1339)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
___
## π‘νμ΄
- <b>νμ(Greedy) μκ³ λ¦¬μ¦</b>μ(λ₯Ό) μ¬μ©νμλ€.
	- λ°©μ μμ μΈμ°λ―μ΄ μμ λ§λ€μ΄λ³΄μ.
		> ex) ABC + BCD
		> - 110B + 100A + 11C + D
		> - κ³μκ° ν° μμλλ‘ 9, 8, ... 1μ κ°κ° λμνμ¬ λν΄μ£Όλ©΄ λλ€.
___
## β νΌλλ°±
___
## π» ν΅μ¬ μ½λ
```c++
int main(){
	...
	vector<int> alphabet(26);
	for (int i = 0; i < N; i++) 
		for (int j = word[i].size() - 1, d = 1; j >= 0; j--, d *= 10) 
			alphabet[word[i][j] - 'A'] += d;
	sort(alphabet.begin(), alphabet.end(), greater<int>());
	
	int ans = 0;
	int num = 9;
	int idx = 0;
	while (alphabet[idx] != 0) 
		ans += alphabet[idx++] * num--;	

	cout << ans;
	...
}
```