#include <iostream>

using namespace std;

int dp[21][21][21];
void print(int a, int b, int c);
int function(int a, int b, int c);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        print(a, b, c);
    }

    return 0;
}

void print(int a, int b, int c) {
    cout << "w(" << a << ", " << b << ", " << c << ") = " << function(a,b,c) << '\n';
}

int function(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20) {
        if (dp[20][20][20] != 0)
            return dp[20][20][20];
        return dp[20][20][20] = function(20, 20, 20);
    }

    if (dp[a][b][c] != 0)
        return dp[a][b][c];
    else if (a < b && b < c) {
        int r1, r2, r3;
        r1 = function(a, b, c - 1);
        r2 = function(a, b - 1, c - 1);
        r3 = function(a, b - 1, c);

        return dp[a][b][c] = r1 + r2 - r3;
    }
    else {
        int r1, r2, r3, r4;
        r1 = function(a - 1, b, c);
        r2 = function(a - 1, b - 1, c);
        r3 = function(a - 1, b, c - 1);
        r4 = function(a - 1, b - 1, c - 1);

        return dp[a][b][c] = r1 + r2 + r3 - r4;
    }
}