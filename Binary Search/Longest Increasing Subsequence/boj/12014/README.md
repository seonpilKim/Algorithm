# [[12014] ์ฑ์ ๋ฆฌ](https://www.acmicpc.net/problem/12014)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
1. <b>์ฃผ๊ฐ๊ฐ ์ค๋ฅผ ๋๋ง ์ฌ๋ ๋ฐฉ๋ฒ์ LIS๋ฅผ ๊ตฌํ๋ ๋ฐฉ๋ฒ์ผ๋ก ๊ตฌํ  ์ ์๋ค.</b>
	- LIS์ ๊ธธ์ด๊ฐ K ์ด์์ด๋ผ๋ฉด, ์กฐ๊ฑด์ ๋ง์กฑํ๊ฒ ์ฃผ์์ ๊ตฌ์ํ  ์ ์๋ค.
___
## ๐กํ์ด
- <B>์๊ณ ๋ฆฌ์ฆ & ์๋ฃ๊ตฌ์กฐ</B>
	- `LIS(Longest Increasing Subsequence)`
- <b>๊ตฌํ</b>
	- `LIS์ ๊ธธ์ด`๋ฅผ ๊ตฌํ๊ธฐ ์ํด ์๋ ฅ ๋ฐ์ ์์ด์ ์์ฐจ ํ์ํ๋ฉด์ ์๋์ ์์์ ์งํํ์๋ค.
		- LIS ๋ฐฐ์ด์ด empty์ด๊ฑฐ๋, ๋งจ ๋ ์์๋ณด๋ค ํฌ๋ค๋ฉด, LIS ๋ฐฐ์ด์ ํ์ฌ ์์ ์ฝ์
		- ์์ ๋ ๊ฒฝ์ฐ๊ฐ ๋ชจ๋ ์๋๋ผ๋ฉด, LIS ๋ฐฐ์ด์์ ํ์ฌ ์์๊ฐ ๋ค์ด๊ฐ ์์น๋ฅผ ์ด๋ถ ํ์ํ์ฌ ๊ต์ฒด
___
## โ ํผ๋๋ฐฑ
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
int main() {
	...

	for (int t = 1; t <= T; t++) {
		int N, K;
		cin >> N >> K;

		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];

		vector<int> LIS;
		for (int i = 0; i < N; i++) {
			if (LIS.empty() || LIS.back() < v[i])
				LIS.push_back(v[i]);
			else {
				int idx = lower_bound(LIS.begin(), LIS.end(), v[i]) - LIS.begin();
				LIS[idx] = v[i];
			}
		}
		cout << "Case #" << t << '\n';
		if (LIS.size() >= K)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	...
}
```