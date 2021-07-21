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

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> jewelry(N);
	vector<int> bag(K);
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) 
		cin >> jewelry[i].first >> jewelry[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(bag.begin(), bag.end());
	sort(jewelry.begin(), jewelry.end());

	long long ans = 0;
	int idx = 0;
	for (int i = 0; i < K; i++) { 
		int limitWeight = bag[i];

		while (idx < N && jewelry[idx].first <= limitWeight) 
			pq.push(jewelry[idx++].second);

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}