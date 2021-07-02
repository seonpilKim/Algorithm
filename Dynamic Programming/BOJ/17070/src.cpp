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
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<vector<bool>> blank(N + 1, vector<bool>(N + 1, false));
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(3, 0)));
	int input;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			if (input == 0)
				blank[i][j] = true;
		}
	}

	dp[1][1][HORIZONTAL] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (j + 1 <= N && blank[i][j + 1]) {
				if (j + 2 <= N && blank[i][j + 2]) {
					dp[i][j + 1][HORIZONTAL] += dp[i][j][HORIZONTAL];
					if (i + 1 <= N && blank[i + 1][j + 2] && blank[i + 1][j + 1])
						dp[i][j + 1][DIAGONAL] += dp[i][j][HORIZONTAL];
				}
			}
			if (i + 1 <= N && blank[i + 1][j]) {
				if (i + 2 <= N && blank[i + 2][j]) {
					dp[i + 1][j][VERTICAL] += dp[i][j][VERTICAL];
					if (j + 1 <= N && blank[i + 2][j + 1] && blank[i + 1][j + 1])
						dp[i + 1][j][DIAGONAL] += dp[i][j][VERTICAL];
				}
			}
			if (i + 1 <= N && j + 1 <= N && blank[i + 1][j + 1]) {
				if (j + 2 <= N && blank[i + 1][j + 2])
					dp[i + 1][j + 1][HORIZONTAL] += dp[i][j][DIAGONAL];
				if (i + 2 <= N && blank[i + 2][j + 1])
					dp[i + 1][j + 1][VERTICAL] += dp[i][j][DIAGONAL];
				if (i + 2 <= N && j + 2 <= N && blank[i + 1][j + 2] && blank[i + 2][j + 1] && blank[i + 2][j + 2])
					dp[i + 1][j + 1][DIAGONAL] += dp[i][j][DIAGONAL];
			}
		}
	}

	cout << dp[N - 1][N - 1][DIAGONAL] + dp[N - 1][N][VERTICAL] + dp[N][N - 1][HORIZONTAL];

    return 0;
}