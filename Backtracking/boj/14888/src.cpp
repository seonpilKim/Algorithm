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
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

int minValue = 1000000001, maxValue = -1000000001;
int N;
vector<int> seq;
vector<int> opr(4);

void DFS(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	seq.resize(N);
	for (int i = 0; i < N; i++)
		cin >> seq[i];
	for (int i = 0; i < 4; i++)
		cin >> opr[i];
	
	DFS(1, seq[0]);
	cout << maxValue << '\n' << minValue;

    return 0;
}

void DFS(int n, int result) {
	if (n == N) {
		if (result < minValue)
			minValue = result;
		if (result > maxValue)
			maxValue = result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opr[i]) {
			opr[i]--;
			if (i == 0)
				DFS(n + 1, result + seq[n]);
			else if (i == 1)
				DFS(n + 1, result - seq[n]);
			else if (i == 2)
				DFS(n + 1, result * seq[n]);
			else if (i == 3)
				DFS(n + 1, result / seq[n]);
			opr[i]++;
		}
	}
}

