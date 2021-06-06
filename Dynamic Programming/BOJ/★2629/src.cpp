#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
int M;
vector<int> sinkers;
vector<vector<bool>> dp;

void DFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	sinkers.assign(N + 1, 0);
	for (int i = 0; i < N; i++)
		cin >> sinkers[i];
	dp.assign(N + 1, vector<bool>(15001, false));

	DFS(0, 0);

	cin >> M;
	while(M--) {
		int bead;
		cin >> bead;
		
		if (bead > 15000 || dp[N][bead] == false)
			cout << "N ";
		else if (dp[N][bead] == true)
			cout << "Y ";
	}

	return 0;
}

// Top-down
void DFS(int cnt, int result) {
	if (cnt > N || dp[cnt][result])
		return;

	dp[cnt][result] = true;

	DFS(cnt + 1, result + sinkers[cnt]);
	DFS(cnt + 1, result);
	DFS(cnt + 1, abs(sinkers[cnt] - result));
}