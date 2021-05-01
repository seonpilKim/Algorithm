#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int longest = 0;
    int N;
    int seq[1000];
    int dp[1000];
    int rdp[1000];

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> seq[i];

    // Base condition
    fill(dp, dp + 1000, 1);
    fill(rdp, rdp + 1000, 1);

    // Bottom-up
//----------------------------------------------------
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < i; j++) 
            if (seq[j] < seq[i] && dp[i] < dp[j] + 1) 
                dp[i] = dp[j] + 1;

    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j > i; j--)
            if (seq[j] < seq[i] && rdp[i] < rdp[j] + 1)
                rdp[i] = rdp[j] + 1;
//-----------------------------------------------------            
    for (int i = 0; i < N; i++) 
        if (longest < dp[i] + rdp[i] - 1) 
            longest = dp[i] + rdp[i] - 1;
    
    cout << longest;

    return 0;
}