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
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;

	return res;
}

long long getFibonacci(long long n) {
	matrix res = {{1, 0}, {0, 1}};
	matrix c = {{1, 1}, {1, 0}};

	while (n) {
		if (n % 2)
			res = res * c;
		c = c * c;
		n /= 2;
	}

	return res[0][1];
}

long long getGcd(long long a, long long b) {
	if (b == 0)
		return a;

	return getGcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	cout << getFibonacci(getGcd(a, b));

	return 0;
}