#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    long long dp[101];

    cin >> T;

    // base condition
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    // bottom-up
    for (int i = 6; i <= 100; i++) 
        dp[i] = dp[i - 1] + dp[i - 5];
    

    while (T--) {
        int N;

        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}