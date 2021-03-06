# [[15811] λ³΅λ©΄μ°?!](https://www.acmicpc.net/problem/15811)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## π€μ κ·Ό
1. <b>μ£Όμ΄μ§ λ¨μ΄λ€μ μνλ²³μ κ°κ° 0 ~ 9λ₯Ό ν λ²μ© λ£μμ λ λμ¬ μ μλ λͺ¨λ  κ²½μ°μ μλ₯Ό λ°μ Έλ³΄μ.</b>
___
## π‘νμ΄
- <B>μκ³ λ¦¬μ¦ & μλ£κ΅¬μ‘°</B>
	- `Backtracking`
- <b>κ΅¬ν</b>
	- μλ ₯λ λ¨μ΄(`string word[3]`) μμλλ‘ ν μνλ²³μ© νμνλ©΄μ, κ°κ° 0 ~ 9μ μ«μλ₯Ό ν λ²μ© λΆμ¬νμλ€.
	- ν΄λΉ μ«μκ° μ΄μ μ μ¬μ©λμλμ§ μ²΄ν¬νκΈ° μν΄ `vector<bool> isUsedNum(10)` μ μ΄μ©νμλ€.
	- κ° μνλ²³μ΄ μ΄λ―Έ μ«μλ₯Ό λΆμ¬ λ°μλ€λ©΄, λΆμ¬λ μ«μλ₯Ό κ·Έλλ‘ μ¬μ©νκΈ° μν΄ `vector<int> match(26, NONE)` μ μ΄μ©νμλ€.
		- κ° λ¬Έμμ `-'A'`μ ν΄μ£Όλ©΄, μΈλ±μ€ 0λΆν° 25κΉμ§ ννν  μ μλ€.
	- DFS ν¨μμ λ§€κ°λ³μ n, m, vλ κ° λ¨μ΄λ₯Ό νμνλ μΈλ±μ€μ΄λ€.
		- λͺ¨λ  λ¨μ΄μ μ«μκ° λΆμ¬λμμ λ, κ°κ° μ«μλ‘ λ³ννμ¬ μμ΄ μ±λ¦½νλ©΄ `exit(0)`μ νΈμΆν΄μ νλ‘κ·Έλ¨μ μ¦μ μ’λ£νμλ€.
	- λ§μ½, λͺ¨λ  κ²½μ°μ μλ₯Ό νμνμμλ νλ‘κ·Έλ¨μ΄ μ¬μ ν μ€ν μ€μ΄λΌλ©΄, μμ΄ μ±λ¦½ν  μ μλ€λ λ»μ΄ λλ€.
___
## β νΌλλ°±
1. <B>μ²μμ `unorderd_map`μ μ¬μ©νμλλ°, TLEμ λ°μλ€.</B>
	- μλ§ μλ£κ΅¬μ‘° λ΄λΆμ μΌλ‘ μ²λ¦¬νλ μ°μ°μ΄ λ λ³΅μ‘νκΈ° λλ¬Έμ΄λΌ μκ°λλ€.
	- `vector<int> match(26, NONE)`μ μ΄μ©νμ¬ `O(1)`μ ν΄λΉ λ¬Έμκ° μ¬μ©λμλμ§ νμΈν  μ μμλ€.
___
## π» ν΅μ¬ μ½λ
```c++
bool ans;
string word[3];
vector<int> match(26, NONE);
vector<bool> isUsedNum(10);

void DFS(int n, int m, int v) {
	if (v == word[2].size()) {
		int res1 = 0, res2 = 0, sum = 0;

		for (int i = word[0].size() - 1, p = 1; i >= 0; i--, p *= 10)
			res1 += match[word[0][i] - 'A'] * p;
		for (int i = word[1].size() - 1, p = 1; i >= 0; i--, p *= 10)
			res2 += match[word[1][i] - 'A'] * p;
		for (int i = word[2].size() - 1, p = 1; i >= 0; i--, p *= 10)
			sum += match[word[2][i] - 'A'] * p;

		if (res1 + res2 == sum) {
			cout << "YES";
			exit(0);
		}
		return;
	}

	if (n < word[0].size()) {
		if (match[word[0][n] - 'A'] >= 0) {
			DFS(n + 1, m, v);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (isUsedNum[i])
				continue;

			isUsedNum[i] = true;
			match[word[0][n] - 'A'] = i;
			DFS(n + 1, m, v);
			isUsedNum[i] = false;
			match[word[0][n] - 'A'] = NONE;
		}
	}
	else if (m < word[1].size()) {
		if (match[word[1][m] - 'A'] >= 0) {
			DFS(n, m + 1, v);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (isUsedNum[i])
				continue;

			isUsedNum[i] = true;
			match[word[1][m] - 'A'] = i;
			DFS(n, m + 1, v);
			isUsedNum[i] = false;
			match[word[1][m] - 'A'] = NONE;
		}
	}
	else if (v < word[2].size()) {
		if (match[word[2][v] - 'A'] >= 0) {
			DFS(n, m, v + 1);
			return;
		}

		for (int i = 0; i <= 9; i++) {
			if (isUsedNum[i])
				continue;

			isUsedNum[i] = true;
			match[word[2][v] - 'A'] = i;
			DFS(n, m, v + 1);
			isUsedNum[i] = false;
			match[word[2][v] - 'A'] = NONE;
		}
	}
}
```