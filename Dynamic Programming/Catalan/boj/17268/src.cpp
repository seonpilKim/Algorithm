#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <math.h>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <bitset>

using namespace std;

#define NONE -1
#define MOD (int)(1e4 + 7);
#define MIN -1
#define MAX 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> dp(N + 1);

    dp[0] = 1;
    dp[2] = 1;

    for (int i = 4; i <= N; i += 2)
        for (int j = 2; j <= i; j += 2)
            dp[i] = (dp[i] + dp[j - 2] * dp[i - j]) % 987654321;

    cout << dp[N];

    return 0;
}