#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <numeric>

#define NCOLOR 3
#define MAX 1000 * 1000 + 1

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> costs(N + 1, vector<int>(NCOLOR, 0));	
	vector<vector<int>> dp(N + 1, vector<int>(NCOLOR, 0));

	for (int i = 1; i <= N; i++) 
		for (int j = 0; j < NCOLOR; j++)
			cin >> costs[i][j];
	
	int answer = MAX;
	for (int color = 0; color < NCOLOR; color++) {

		for (int i = 0; i < NCOLOR; i++) {
			if (i == color)
				dp[1][i] = costs[1][i];
			else
				dp[1][i] = MAX;
		}

		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
		}

		for (int i = 0; i < NCOLOR; i++)
			if (i != color) 
				answer = min(answer, dp[N][i]);
	}

	cout << answer;

	return 0;
}