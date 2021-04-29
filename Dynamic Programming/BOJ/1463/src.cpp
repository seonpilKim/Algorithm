#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int dp[1000001];
int f(int num);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    cout << f(N);
    
    return 0;
}

int f(int num) {
    int r1 = INT_MAX, r2 = INT_MAX, r3 = INT_MAX;
    
    // Base condition
    if (num == 1)
        return 0;
    // Memoization
    if (dp[num] != 0)
        return dp[num];

    // Top-down
    if (num % 3 == 0)
        r1 = f(num / 3) + 1;
    if (num % 2 == 0)
        r2 = f(num / 2) + 1;
    r3 = f(num - 1) + 1;

    return dp[num] = min({r1,r2,r3});
}