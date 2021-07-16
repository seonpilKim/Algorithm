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

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> applicant(N);
		for (int i = 0; i < N; i++)
			cin >> applicant[i].first >> applicant[i].second;
		sort(applicant.begin(), applicant.end());

		vector<pair<int, int>> selected;
		selected.push_back(applicant.front());
		for (int i = 1; i < N; i++) {
			if (applicant[i].first > selected.back().first && applicant[i].second < selected.back().second)
				selected.push_back(applicant[i]);
		}

		cout << selected.size() << '\n';
	}

	return 0;
}