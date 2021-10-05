# 타일 채우기(Tilling)
## 🤔접근
- `dp[i]` : `i번째 타일까지 조건을 만족하도록 채울 수 있는 경우의 수`
    - <b>기저 조건</b>
        - `dp[0]`: `1` -> 아무 것도 채우지 않는 경우의 수는 1이다.
        - `dp[초기 index]` -> `벽의 크기`와 `타일의 종류`에 따라 타일을 채울 수 있는 경우의 수를 설정
            > <b>ex) 2 x n 크기의 벽에, 2 x 1, 1 x 2 타일을 채울 수 있는 경우의 수</b><br>
            > `dp[1]` -> 1 x 2 타일만 채울 수 있으므로 경우의 수는 1<br>
            > `dp[2]` -> 1 x 2 타일 두 개 혹은 2 x 1 타일 두 개를 채울 수 있으므로 경우의 수는 2
## 📂종류
- [벽: `2 x N` | 타일: `2 x 1, 1 x 2`](https://github.com/seonpilKim/Algorithm/tree/master/Dynamic%20Programming/Tilling/boj/11726)
- [벽: `2 x N` | 타일: `2 x 1, 1 x 2, 2 x 2`](https://github.com/seonpilKim/Algorithm/tree/master/Dynamic%20Programming/Tilling/boj/11727)
- [벽: `2 x N` | 타일: `1 x 1, 2 x 1, 1 x 2`](https://github.com/seonpilKim/Algorithm/tree/master/Dynamic%20Programming/Tilling/boj/14852)
- [벽: `3 x N` | 타일: `2 x 1, 1 x 2`](https://github.com/seonpilKim/Algorithm/tree/master/Dynamic%20Programming/Tilling/boj/2133)
- [벽: `3 x N(≤10¹⁸)` | 타일: `2 x 1, 1 x 2`](https://github.com/seonpilKim/Algorithm/tree/master/Dynamic%20Programming/Tilling/boj/13976)
- [벽: `4 x N` | 타일: `2 x 1, 1 x 2`](https://github.com/seonpilKim/Algorithm/tree/master/Dynamic%20Programming/Tilling/boj/2718)