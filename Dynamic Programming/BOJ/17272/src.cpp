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

const long long MOD = 1e9 + 7;
typedef vector<vector<long long>> matrix;

matrix operator* (const matrix& a, const matrix& b) {
	int n = a.size();
	matrix result(n, vector<long long>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, M;
	cin >> N >> M;

	// 행렬 계수
	matrix m(M, vector<long long>(M));
	m[0][0] = m[0][M - 1] = 1;
	for (int i = 1; i < M; i++)
		m[i][i - 1] = 1;

	// 단위 행렬로 초기화
	matrix ans(M, vector<long long>(M));
	for (int i = 0; i < M; i++)
		ans[i][i] = 1;

	// 분할 정복
	while (N) {
		if (N & 1)
			ans = ans * m;
		m = m * m;
		N /= 2;
	}

	cout << ans[0][0];

	return 0;
}