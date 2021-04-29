#include <iostream>

using namespace std;

int dp[301][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int point;
        cin >> point;
        dp[i][0] = dp[i][1] = point;
    }

    // Bottom-up
    for (int i = 2; i <= N; i++) {
        dp[i][0] += dp[i - 2][1];
        dp[i][1] += max(dp[i - 1][0], dp[i - 2][1]);
    }

    cout << max(dp[N][0], dp[N][1]);

    return 0;
}
