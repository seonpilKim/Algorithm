#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int dp[501][501];

    cin >> N;

    for (int i = 1; i <= N; i++) 
        for (int j = 0; j < i; j++) 
            cin >> dp[i][j];
        
    // Bottom-up
    for (int i = N; i > 1; i--) 
        for (int j = 0; j < N - 1; j++) 
            dp[i - 1][j] += max(dp[i][j], dp[i][j + 1]);

    cout << dp[1][0];
   
    return 0;
}