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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> LCS(str1.size() + 1, vector<int>(str2.size() + 1));

    // find LCS length
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (str1[i - 1] == str2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    int i = str1.size();
    int j = str2.size();
    int len = LCS[str1.size()][str2.size()];
    stack<char> subseq;

    cout << len << '\n';

    // find LCS
    while (len) {
        if (LCS[i - 1][j] == len)
            i--;
        else if (LCS[i][j - 1] == len)
            j--;
        else {
            subseq.push(str1[i - 1]);
            i--;
            j--;
            len--;
        }
    }

    while (!subseq.empty()) {
        cout << subseq.top();
        subseq.pop();
    }

    return 0;
}
