# [[16953] A -> B](https://www.acmicpc.net/problem/16953)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
1. <b>A์ 2๋ฅผ ๊ณฑํ๊ฑฐ๋, 1์ ๋งจ ์ค๋ฅธ์ชฝ์ ์ถ๊ฐํ๋ฉด์ B๋ฅผ ๋ง๋ค์ด์ผ ํ๋ค.</b>
	- ๊ฐ ์ ์ ๋ง๋ค ๊ฐ์ค์น๊ฐ 1๋ก ๋์ผํ ๊ฒฝ๋ก๊ฐ 2๊ฐ์ฉ ์๋ ๋ฐฉํฅ ๊ทธ๋ํ๋ผ๊ณ  ์๊ฐํ์.
	- ๊ทธ๋ ๋ค๋ฉด, BFS๋ก ํด๊ฒฐํ  ์ ์๋ค.
___
## ๐กํ์ด
- <b>BFS ์๊ณ ๋ฆฌ์ฆ, unordered_map(hash map)</b>์(๋ฅผ) ์ฌ์ฉํ์๋ค.
	- BFS๋ฅผ ์ด์ฉํ์ฌ A์์ B๋ฅผ ๋ง๋๋ ์ต์ ์ฐ์ฐ ํ์๋ฅผ ์ฐพ๋๋ก ๊ตฌํํ์๋ค.
	- ๊ฐ ์ ์ (A๋ฅผ ๋ณํํ ๊ฐ)๋ง๋ค A๋ถํฐ์ ์ต์ ์ฐ์ฐ ํ์๋ฅผ ์ ์ฅํด์ผ ํ๋ค.
		- ๋ํ ์ด ๊ฐ๋ค์ ์ ๋ ฌํด์ ์ ์ฅํ  ํ์๊ฐ ์์ผ๋ฏ๋ก unorderd_map์ ์ ์ฅํ์๋ค.
___
## โ ํผ๋๋ฐฑ
1. <b>int์ long long์ ๊ฐ ๋น๊ต๋ ๊ฐ๋ฅํ ๊ฒ ๊ฐ๋ค.</b>
2. <b>lValue ํ์์ด long long์ด๋ผ๋ฉด, rValue ํ์๋ long long์ด์ด์ผ ํ๋ค.</b>
	- rValue ํ์์ด int๋ผ๋ฉด overflow๊ฐ ๋ฐ์ํ๋ค.
3. <b>1๋ถํฐ B๊น์ง ๋ชจ๋  ์ซ์์ ๋ํด ์ฐ์ฐ์ ํ์๋ฅผ ์ ์ฅํด์๋ ์ ๋๋ค.</b>
	- ์ต๋ 10โน * 4byte ๋ฉ๋ชจ๋ฆฌ๋ฅผ ํ ๋นํด์ผ ํ๋ค.
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
while (!next.empty()) {
	while (!next.empty()) {
		cur.push(next.front());
		next.pop();
	}

	while (!cur.empty()) {
		long long n = cur.front();
		cur.pop();
		m[n] = cnt;
		
		int Multiply2 = 2 * n;
		long long addToRight1 = n * 10 + 1;

		if (Multiply2 <= B) {
			if (m.find(Multiply2) == m.end()) 
				next.push(Multiply2);
			else if (m[Multiply2] > cnt + 1) 
				next.push(Multiply2);
		}
		if (addToRight1 <= B) {
			if (m.find(addToRight1) == m.end())
				next.push(addToRight1);
			else if (m[addToRight1] > cnt + 1)
				next.push(addToRight1);
		}
	}
	cnt++;
}
```