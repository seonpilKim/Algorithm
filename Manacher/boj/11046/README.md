# [[11046] ํฐ๋ฆฐ๋๋กฌ??](https://www.acmicpc.net/problem/11046)

![](imgs/1.PNG)
![](imgs/2.PNG)
___
## ๐ค์ ๊ทผ
___
## ๐กํ์ด
- <B>์๊ณ ๋ฆฌ์ฆ & ์๋ฃ๊ตฌ์กฐ</B>
	- `Manacher`
___
## โ ํผ๋๋ฐฑ
- ์น ํ์ ์ ์ ์๋ 10๋ง ์ดํ์ ์ซ์ ์ด๋ฏ๋ก, ๋ฐฐ์ด์ ๊ฐ๊ฐ ์๋ ฅํด์ ํฐ๋ฆฐ๋๋กฌ์ธ์ง ํ๋ณํด์ผ ํ๋ค.
    - ๋ฐฐ์ด์ ๊ฐ ๊ฐ๋ค์ ํ๋์ ๋ฌธ์๋ผ๊ณ  ์๊ฐํ์.
- S์ E ์ฌ์ด์ ์์ฐ์๊ฐ ํฐ๋ฆฐ๋๋กฌ์ธ์ง ํ์ธํ๊ธฐ ์ํด S์ E ์ค๊ฐ ์์น์ `A[mid]`(mid๋ฒ์งธ ๋ฌธ์๋ฅผ ์ค์ฌ์ผ๋ก ํ๋ ๊ฐ์ฅ ๊ธด ํฐ๋ฆฐ๋๋กฌ์ ๋ฐ์ง๋ฆ ๊ธธ์ด)๋ฅผ ๊ตฌํ๊ณ , E - S + 1๊ณผ ๊ฐ์์ง ๋น๊ตํ์.
    - ์ฟผ๋ฆฌ๋ง๋ค ๊ฐ๊ฐ Manacher ์๊ณ ๋ฆฌ์ฆ์ ์ํํ๋ฉด ์๊ฐ์ด๊ณผ์ด๋ฏ๋ก ์ฃผ์!
___
## ๐ป ํต์ฌ ์ฝ๋
```c++
vector<int> A;

vector<int> convert(const vector<int>& str) {
    int len = str.size();
    vector<int> res;

    for (int i = 0; i < len; i++) {
        res.push_back(0);
        res.push_back(str[i]);
    }
    res.push_back(0);

    return res;
}

void manachers(const vector<int>& S) {
    vector<int> str = convert(S);
    int r = 0, p = 0;
    int N = str.size();
    A.resize(N);

    for (int i = 0; i < N; i++) {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;

        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && str[i - A[i] - 1] == str[i + A[i] + 1])
            A[i]++;

        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}

int main() {
    ...

    manachers(str);

    for (int i = 0; i < T; i++) {
        int src, dest;
        cin >> src >> dest;

        if (A[((src * 2 - 1) + (dest * 2 - 1)) / 2] >= dest - src + 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}
```