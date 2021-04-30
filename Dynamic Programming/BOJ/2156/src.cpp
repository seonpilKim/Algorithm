#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int table[10000] = {0};
    int dp[10000] = {0};

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> table[i];

    // Base condition
    dp[1] = table[1];
    if (n > 1)
        dp[2] = table[1] + table[2];

    // Bottom-up
    for (int i = 3; i <= n; i++) 
        dp[i] = max(dp[i - 1], max(dp[i - 2] + table[i], dp[i - 3] + table[i - 1] + table[i]));
    
    cout << dp[n];

    return 0;
}