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

	int N;
	cin >> N;

	vector<string> word(N);
	for (int i = 0; i < N; i++)
		cin >> word[i];

	vector<int> alphabet(26);
	for (int i = 0; i < N; i++) 
		for (int j = word[i].size() - 1, d = 1; j >= 0; j--, d *= 10) 
			alphabet[word[i][j] - 'A'] += d;
	sort(alphabet.begin(), alphabet.end(), greater<int>());
	
	int ans = 0;
	int num = 9;
	int idx = 0;
	while (alphabet[idx] != 0) 
		ans += alphabet[idx++] * num--;	

	cout << ans;

	return 0;
}