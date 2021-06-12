#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> memory(N + 1);
	vector<int> cost(N + 1);
	for (int i = 0; i < N; i++)
		cin >> memory[i];
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	vector<int> dp(10001);
	for (int i = 0; i < N; i++)
		for (int j = 10000; j >= cost[i]; j--)
			dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M) {
			cout << i;
			break;
		}
	}

	return 0;
}