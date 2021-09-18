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

string convert(const string& str) {
    int len = str.size();
    string res = "";

    for (int i = 0; i < len; i++) {
        res += '#';
        res += str[i];
    }
    res += '#';

    return res;
}

int manachers(const string& S) {
    string str = convert(S);
    int r = 0, p = 0;
    int N = str.size();
    vector<int> A(N);

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

    return *max_element(A.begin(), A.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    cout << manachers(str);
    
    return 0;
}
