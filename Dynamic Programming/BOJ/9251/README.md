## [[9251] LCS](https://www.acmicpc.net/problem/9251)

![](imgs/1.PNG)
___
## ๐กํ์ด
- ๋์ ๊ณํ๋ฒ์ ์ด์ฉํ์๋ค.
- Bottom-up ๋ฐฉ์์ผ๋ก ๊ตฌํํ์๋ค.
	- ์ฒซ ๋ฒ์งธ ๋ฌธ์์ด str์ ๋ฌธ์๋ฅผ ์์๋๋ก ํ์ํ๋ฉด์, cmp์ ๋ฌธ์์ด์ ๊ฐ ๋ฌธ์๋ฅผ ์์๋๋ก ๊ฐ์ ธ์์ ๋น๊ตํ๋ค.
    - `dp[i][j]`์ `์ฒซ ๋ฒ์งธ ๋ฌธ์์ด์ 1 ~ i ๋ถ๋ถ ๋ฌธ์์ด`๊ณผ `๋ ๋ฒ์งธ ๋ฌธ์์ด์ 1 ~ j ๋ถ๋ถ ๋ฌธ์์ด`์ ๋น๊ตํ์ ๋์ `LCS๊ฐ`์ ์ ์ฅํ๋ค.
    - ์ ํ์
        - ์ฒซ ๋ฒ์งธ ๋ฌธ์์ด์ i ๋ฒ์งธ ๋ฌธ์์ ๋ ๋ฒ์งธ ๋ฌธ์์ด์ j ๋ฒ์งธ ๋ฌธ์๊ฐ `๋์ผํ` ๊ฒฝ์ฐ
            - `dp[i][j] = dp[i - 1][j - 1] + 1`
            - ๋ ๋ฌธ์์ด ๊ฐ๊ฐ ํ์ฌ ๋ฌธ์์์ ํ ์นธ ์ด์ ์ ๋ฌธ์๊น์ง ๋น๊ตํ์ ๋์ LCS๊ฐ์ 1์ ๋ํ์ฌ ํ์ฌ(i, j) LCS๊ฐ์ ์ ์ฅํ๋ค.
                > ex) i = 2, j = 2์ธ ๊ฒฝ์ฐ<br>
                > - ์ฒซ ๋ฒ์งธ ๋ถ๋ถ ๋ฌธ์์ด(0~1)๊ณผ ๋ ๋ฒ์งธ ๋ถ๋ถ ๋ฌธ์์ด(0~1)์ ๋น๊ตํ์ ๋์ LCS๊ฐ์ 1์ ๋ํ์ฌ dp[2][2]์ ์ ์ฅ
        - ๊ทธ๋ ์ง ์์ ๊ฒฝ์ฐ
            - `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`
            - ๋ ๋ฌธ์์ด์ ํ ๋ฒ์ฉ ๋ฒ๊ฐ์์ ํ ์นธ ์ด์ ์ ๋ฌธ์์ ๊ฐ๊ฐ ๋น๊ตํ์ ๋์ LCS๊ฐ ์ค, max๊ฐ์ ํ์ฌ(i, j) LCS๊ฐ์ ์ ์ฅํ๋ค.
                > ex) i = 2, j = 2์ธ ๊ฒฝ์ฐ<br>
                > 1. ์ฒซ ๋ฒ์งธ ๋ถ๋ถ ๋ฌธ์์ด(0~1)๊ณผ ๋ ๋ฒ์งธ ๋ถ๋ถ ๋ฌธ์์ด(0~2) ๋น๊ต<br>
                > 2. ์ฒซ ๋ฒ์งธ ๋ถ๋ถ ๋ฌธ์์ด(0~2)๊ณผ ๋ ๋ฒ์งธ ๋ถ๋ถ ๋ฌธ์์ด(0~1) ๋น๊ต
    - ์์
        - ![](imgs/2.PNG)
```c++
// Base condition : dp[0][1 ~ cmp.size()], dp[1 ~ str.size()][0] = 0

// Bottom-up
for (int i = 1; i <= str.size(); i++) {
    for (int j = 1; j <= cmp.size(); j++) {
        if (str[i - 1] == cmp[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
}

cout << dp[str.size()][cmp.size()];
```