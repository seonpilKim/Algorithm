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
#define MAX 1e3 + 1
#define MOD (int)(1e4 + 7);

const int dr[] = {0, 1, 0, -1};
const int dc[] = {-1, 0, 1, 0};

bool topologicalSort(const vector<vector<int>>& adj, vector<int>& inDegree, const int& N, vector<int>& result) {
    queue<int> q;
    vector<int> time(N + 1);

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
        time[i] = result[i];
    }

    for (int u = 1; u <= N; u++) {
        if (q.empty())
            return false;

        int cur = q.front();
        q.pop();
 
        for (int next : adj[cur]) {
            if (--inDegree[next] == 0) 
                q.push(next);
            result[next] = max(result[next], result[cur] + time[next]);
        }
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> result(N + 1);
    vector<int> inDegree(N + 1);
    vector<vector<int>> adj(N + 1, vector<int>());

    for (int u = 1; u <= N; u++) {
        cin >> result[u];
        while (true) {
            int v;
            cin >> v;
            if (v == -1)
                break;
            adj[v].push_back(u);
            inDegree[u]++;
        }
    }

    topologicalSort(adj, inDegree, N, result);

    for (int i = 1; i <= N; i++)
        cout << result[i] << '\n';

	return 0;
}