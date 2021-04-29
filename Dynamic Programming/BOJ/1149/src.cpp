#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R[1001];
    int G[1001];
    int B[1001];

    int N;
    int answer;

    cin >> N;

    for (int i = 1; i <= N; i++) 
        cin >> R[i] >> G[i] >> B[i];

    // Bottom-up
    for (int i = 2; i <= N; i++) {
        R[i] += min(G[i - 1], B[i - 1]);
        G[i] += min(R[i - 1], B[i - 1]);
        B[i] += min(R[i - 1], G[i - 1]);
    }

    cout << min(R[N], min(G[N], B[N]));
   
    return 0;
}