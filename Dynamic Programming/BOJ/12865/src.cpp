#include <iostream>

using namespace std;

int dp[101][100001];
int weight[101];
int value[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) 
		cin >> weight[i] >> value[i];
	
	// Base condition : dp[0][j] = 0

	// Bottom-up
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - weight[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - weight[i]] + value[i]));
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}