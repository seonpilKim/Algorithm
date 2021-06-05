#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> seq(N + 1);
	for (int i = 1; i <= N; i++) 
		cin >> seq[i];

	vector<vector<bool>> dp(N + 1, vector<bool>(N + 1));
	// base condition
	for (int i = 1; i <= N; i++) 
		dp[i][i] = true;
	for (int i = 1; i < N; i++) 
		if (seq[i] == seq[i + 1])
			dp[i][i + 1] = true;

	// bottom-up
	for (int range = 3; range <= N; range++) {
		for (int start = 1; start + range - 1 <= N; start++) {
			int end = start + range - 1;

			if (seq[start] == seq[end] && dp[start + 1][end - 1] == true) 
				dp[start][end] = true;
		}
	}

	int M;
	cin >> M;
	int S, E;
	while (M--) {
		cin >> S >> E;

		if (dp[S][E] == true)
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}

