#include <iostream>

using namespace std;

int dp[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int num;
    int max; 

    cin >> num;

    // Base condition
    dp[0] = max = num;

    // Bottom-up
    for (int i = 1; i < N; i++) {
        cin >> num;
        if (dp[i - 1] >= 0)
            dp[i] = dp[i - 1] + num;
        else
            dp[i] = num;
        if (max < dp[i])
            max = dp[i];
    }
    
    cout << max;

    return 0;
}