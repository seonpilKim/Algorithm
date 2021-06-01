#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<pair<int, int>> matrix(N + 1);
	for (int i = 1; i <= N; i++) {
		int r, c;
		cin >> r >> c;
		matrix[i] = make_pair(r, c);
	}
	
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	for (int range = 1; range < N; range++) {
		for (int first = 1; first + range <= N; first++) {
			int last = first + range;
			dp[first][last] = INT_MAX;

			for (int mid = first; mid < last; mid++) {
				dp[first][last] = min(dp[first][last],
					dp[first][mid] + dp[mid + 1][last]
					+ matrix[first].first * matrix[mid].second * matrix[last].second);
			}
		}
	}
	cout << dp[1][N];

	return 0;
}