#include <iostream>

using namespace std;

pair<int, int> fibonacci(int n);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        pair<int, int> result = fibonacci(n);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}

pair<int, int> operator+ (pair<int, int> left, pair<int, int> right) {
    left.first += right.first;
    left.second += right.second;

    return left;
}

pair<int, int> fibonacci(int n) {
    if (n == 0)
        return make_pair(1, 0);
    else if (n == 1)
        return make_pair(0, 1);

    pair<int, int> dp[41];
    fill(dp, dp + 41, make_pair(0, 0));

    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}