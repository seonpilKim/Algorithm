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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string arithmeticExpression;
	cin >> arithmeticExpression;

	stack<int> s;
	vector<int> num(1);

	for (int i = 0; i < arithmeticExpression.size(); i++) {
		if (arithmeticExpression[i] != '-' && arithmeticExpression[i] != '+')
			s.push(arithmeticExpression[i] - '0');
		else {
			int n = 1;
			while (!s.empty()) {
				num.back() += s.top() * n;
				n *= 10;
				s.pop();
			}

			if (arithmeticExpression[i] == '-')
				num.push_back(0);
		}
	}
	int n = 1;
	while (!s.empty()) {
		num.back() += s.top() * n;
		n *= 10;
		s.pop();
	}

	int sum = num[0];
	for (int i = 1; i < num.size(); i++)
		sum -= num[i];
	cout << sum;

	return 0;
}