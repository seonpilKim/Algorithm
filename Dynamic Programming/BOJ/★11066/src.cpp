#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	while (T--) {
		int K;
		cin >> K;
		
		vector<int> sum(K + 1, 0); // for Prefix-Sum
		vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0));

		for (int i = 1; i <= K; i++) {
			int cost;
			cin >> cost;
			sum[i] = sum[i - 1] + cost;
		}

		// range between two groups : [1, K)
		for (int range = 1; range < K; range++) {
			for (int first = 1; first + range <= K; first++) {
				int last = first + range;
				int prefix_sum = sum[last] - sum[first - 1];
				dp[first][last] = INT_MAX;

				// mid : [first, last)
				for (int mid = first; mid < last; mid++)
					dp[first][last] = min(
						dp[first][last],
						dp[first][mid] + dp[mid + 1][last] + prefix_sum);
					// dp[first][mid] : cost of temporary files (between first file and middle file)
					// dp[mid + 1][last] : cost of temporary files (between middle file and last file)
					// prefix_sum : cost of total files (between first file and last file)
			}
		}

		cout << dp[1][K] << '\n';
	}

	return 0;
}