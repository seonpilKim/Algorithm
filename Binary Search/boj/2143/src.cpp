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

#define NONE -1

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> prefixSumA;
	for (int i = 0; i < N; i++) 
		cin >> A[i];

	int M;
	cin >> M;
	vector<int> B(M);
	vector<int> prefixSumB;
	for (int i = 0; i < M; i++) 
		cin >> B[i];

	for (int i = 0; i < N; i++) {
		int prefixSum = A[i];
		prefixSumA.push_back(prefixSum);
		for (int j = i + 1; j < N; j++) {
			prefixSum += A[j];
			prefixSumA.push_back(prefixSum);
		}
	}

	for (int i = 0; i < M; i++) {
		int prefixSum = B[i];
		prefixSumB.push_back(prefixSum);
		for (int j = i + 1; j < M; j++) {
			prefixSum += B[j];
			prefixSumB.push_back(prefixSum);
		}
	}
	sort(prefixSumB.begin(), prefixSumB.end()); // for binary-search

	long long ans = 0;
	for (auto a : prefixSumA) 
		ans += (upper_bound(prefixSumB.begin(), prefixSumB.end(), T - a) - lower_bound(prefixSumB.begin(), prefixSumB.end(), T - a));
	
	cout << ans;

	return 0;
}