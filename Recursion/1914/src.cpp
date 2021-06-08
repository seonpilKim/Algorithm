#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void hanoi(int n, int start, int by, int dest);
string BigInteger(double val);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	cout << BigInteger(pow(2, N)) << '\n';
	if (N <= 20)
		hanoi(N, 1, 2, 3);

	return 0;
}

string BigInteger(double val) {
	string answer = to_string(val);
	answer = answer.substr(0, answer.find('.'));
	answer[answer.size() - 1] -= 1;
	return answer;
}

void hanoi(int n, int start, int by, int dest) {
	if (n == 1) {
		cout << start << ' ' << dest << '\n';
		return;
	}
	
	hanoi(n - 1, start, dest, by);
	cout << start << ' ' << dest << '\n';
	hanoi(n - 1, by, start, dest);
}