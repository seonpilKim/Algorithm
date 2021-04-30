#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int longest = 1;
    int N;
    int seq[1000];
    int dp[1000];

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> seq[i];

    // Base condition
    fill(dp, dp + 1000, 1);

    // Bottom-up
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (dp[i] > longest)
                    longest = dp[i];
            }
        }
    }
    cout << longest;

    return 0;
}