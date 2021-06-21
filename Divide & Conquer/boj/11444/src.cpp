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
#include <limits.h>
#include <numeric>

#define MOD 1000000007

using namespace std;

typedef vector<vector<long long>> matrix;
matrix operator* (const matrix& a, const matrix& b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;
	
	matrix ans = {{1, 0}, {0, 1}};
	matrix a = {{1, 1}, {1, 0}};

	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	cout << ans[0][1];

	return 0;
}

matrix operator* (const matrix& a, const matrix& b) {
	int n = a.size();
	matrix result(n, vector<long long>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) 
				result[i][j] += a[i][k] * b[k][j];
			result[i][j] %= MOD;
		}
	}

	return result;
}