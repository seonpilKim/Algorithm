#include <iostream>

using namespace std;

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) 
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    
    cout << dp[N];

    return 0;
}
