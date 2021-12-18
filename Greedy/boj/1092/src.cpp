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
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> cranes(N);
	for (int i = 0; i < N; i++)
		cin >> cranes[i];
	sort(cranes.begin(), cranes.end(), greater<int>());
	
	int M;
	cin >> M;
	vector<int> boxes(M);
	for (int i = 0; i < M; i++) 
		cin >> boxes[i];
	sort(boxes.begin(), boxes.end());
	
	if (boxes.back() > cranes.front()) 
		cout << -1;
	else {
		int ans = 0;
		while (!boxes.empty()) {
			ans++;
			for (auto crane : cranes) {
				auto iter = upper_bound(boxes.begin(), boxes.end(), crane);
				if (iter != boxes.begin())
					boxes.erase(--iter);
			}
		}
		cout << ans;
	}

	return 0;
}