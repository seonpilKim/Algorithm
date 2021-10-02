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

int N, M, K;
bool isPossible(const vector<int>& pos, int src, int len, int cnt) {
	int cur = src;
	int next = (src + 1) % M;

	while (src != next) {
		if ((pos[next] - pos[cur] + N) % N >= len) {
			cur = next;
			if (++cnt == K)
				return ((pos[src] - pos[cur] + N) % N >= len ? true : false);
		}
		next = (next + 1) % M;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	vector<int> pos(M); 
	for (int i = 0; i < M; i++)
		cin >> pos[i];

	if (K == 1)
		cout << N;
	else {
		int low = 1, high = N;
		while (low <= high) {
			int mid = (low + high) / 2; 
			bool flag = false;

			for (int i = 0; i < M; i++) {
				if (isPossible(pos, i, mid, 1)) {
					flag = true;
					break;
				}
			}

			flag ? low = mid + 1 : high = mid - 1;
		}

		cout << high;
	}

	return 0;
}