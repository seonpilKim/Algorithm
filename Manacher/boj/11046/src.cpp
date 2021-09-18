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
#define MAX 1e3 + 1
#define MOD (int)(1e4 + 7);

const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dc[] = {-1, 0, 1, 0, -1, 1, -1, 1};
vector<int> A;

vector<int> convert(const vector<int>& str) {
    int len = str.size();
    vector<int> res;

    for (int i = 0; i < len; i++) {
        res.push_back(0);
        res.push_back(str[i]);
    }
    res.push_back(0);

    return res;
}

void manachers(const vector<int>& S) {
    vector<int> str = convert(S);
    int r = 0, p = 0;
    int N = str.size();
    A.resize(N);

    for (int i = 0; i < N; i++) {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;

        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && str[i - A[i] - 1] == str[i + A[i] + 1])
            A[i]++;

        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> str(N);
    for (int i = 0; i < N; i++)
        cin >> str[i];

    manachers(str);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int src, dest;
        cin >> src >> dest;

        if (A[((src * 2 - 1) + (dest * 2 - 1)) / 2] >= dest - src + 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}