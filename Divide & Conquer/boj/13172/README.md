# [[13172] โ](https://www.acmicpc.net/problem/13172)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
1. <b>๊ธฐ๋๊ฐ: `โ(S * Nยฏยน % n)`</b>
	- `Nโฟยฏยฒ โก Nยฏยน (mod n)`์์ด ์ฃผ์ด์ก์ผ๋ฏ๋ก, ๋ถํ ์ ๋ณต์ ํตํด ๋น ๋ฅด๊ฒ Nโฟยฏยฒ์ ๊ตฌํ์.
___
## ๐กํ์ด
- <b>๋ถํ ์ ๋ณต(Divide and Conquer) ์๊ณ ๋ฆฌ์ฆ</b>์(๋ฅผ) ์ฌ์ฉํ์๋ค.
	- n์ 10โน+7์ผ๋ก ๋งค์ฐ ํฌ๋ฏ๋ก, `long long` ์๋ฃํ์ ์ฌ์ฉํ์.
		> intํ์ ์ฌ์ฉํ๋ฉด, ์ฐ์ฐ ์ค์ overflow๊ฐ ๋ฐ์ํ  ์ ์๋ค.
	- ์ฐ์ฐ๋ง๋ค ๋ชจ๋๋ฌ ์ฐ์ฐ์ ์ถ๊ฐ๋ก ์ํํด ์ฃผ์ด์ผ ํ๋ค.
___
## โ ํผ๋๋ฐฑ
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
int main(){
	...
	long long ans = 0;
	for (int i = 0; i < M; i++) {
		int N, S;
		cin >> N >> S;
		
		// convert to reduced fraction(์๋ตํด๋ ์๊ด ์์)
		int g = gcd(N, S);
		N /= g;
		S /= g;

		// (S * Nโฟยฏยฒ) % MOD
		ans += (S * divideAndConquer(N, MOD - 2)) % MOD;
		ans %= MOD;
	}
	
	cout << ans;
}

long long divideAndConquer(long long val, int pow) {
	long long res = 1;

	while (pow) {
		if (pow & 1) // if pow is odd, multiply one more time
			res = (res * val) % MOD;
		val = (val * val) % MOD;
		pow >>= 1;
	}
	
	return res;
}
```