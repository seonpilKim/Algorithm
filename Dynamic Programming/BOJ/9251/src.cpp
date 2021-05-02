#include <iostream>

using namespace std;

int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str, cmp;
    cin >> str >> cmp;

    // Base condition : dp[0][1 ~ cmp.size()], dp[1 ~ str.size()][0] = 0

    // Bottom-up
    for (int i = 1; i <= str.size(); i++) {
        for (int j = 1; j <= cmp.size(); j++) {
            if (str[i - 1] == cmp[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    cout << dp[str.size()][cmp.size()];

    return 0;
}