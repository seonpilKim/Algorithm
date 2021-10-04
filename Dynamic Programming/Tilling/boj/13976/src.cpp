#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 9e9;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

typedef vector<vector<long long>> matrix;

matrix operator* (const matrix& A, const matrix& B) {
	int n = A.size();
	matrix res(n, vector<long long>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res[i][j] = (res[i][j] + A[i][k] * B[k][j] + MOD) % MOD;

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N;
	cin >> N;

	if (N % 2) {
		cout << 0;
		return 0;
	}

	matrix ans = {{1, 0}, {0, 1}};
	matrix c = {{4, -1}, {1, 0}};

	N /= 2; 
	while (N) {
		if (N % 2)
			ans = ans * c;
		c = c * c;
		N /= 2;
	}

	cout << (ans[0][0] + ans[0][1] + MOD) % MOD;

	return 0;
}