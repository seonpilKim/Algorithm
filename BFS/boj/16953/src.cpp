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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;

	unordered_map<int, int> m;
	queue<int> next;
	queue<int> cur;

	int cnt = 0;
	next.push(A);
	while (!next.empty()) {
		while (!next.empty()) {
			cur.push(next.front());
			next.pop();
		}

		while (!cur.empty()) {
			long long n = cur.front();
			cur.pop();

			m[n] = cnt;
			
			int Multiply2 = 2 * n;
			long long addToRight1 = n * 10 + 1;

			if (Multiply2 <= B) {
				if (m.find(Multiply2) == m.end()) 
					next.push(Multiply2);
				else if (m[Multiply2] > cnt + 1) 
					next.push(Multiply2);
			}
			if (addToRight1 <= B) {
				if (m.find(addToRight1) == m.end())
					next.push(addToRight1);
				else if (m[addToRight1] > cnt + 1)
					next.push(addToRight1);
			}
		}
		cnt++;
	}

	if (m.find(B) == m.end())
		cout << -1;
	else
		cout << m[B] + 1;

    return 0;
}
