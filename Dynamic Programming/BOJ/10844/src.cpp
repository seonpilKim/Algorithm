#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    int dp[101][10] = {0};

    for (int i = 1; i < 10; i++) 
        dp[1][i] = 1;
    
    // Bottom-up
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j < 9; j++) 
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;     
    }

    int answer = 0;
    for (int i = 0; i < 10; i++) 
        answer = (answer + dp[N][i]) % 1000000000;
    
    cout << answer;

    return 0;
}