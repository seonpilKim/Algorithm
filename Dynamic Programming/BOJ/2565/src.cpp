#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    vector<pair<int, int>> A;
    int dp[101];

    cin >> N;

    // Base condition
    fill(dp, dp + N, 1);
    
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        A.emplace_back(a, b);
    }
    sort(A.begin(), A.end());


    // Bottom-up
    int longest = 1;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (A[i].second > A[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                if (dp[i] > longest)
                    longest = dp[i];
            }
        }
    }

    cout << N - longest;
    
    return 0;
}