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
#define MOD (int)(1e4 + 7);
#define MIN -1
#define MAX 1

int N;
vector<vector<char>> v;
vector<vector<int>> dp;
int minVal = 100000000, maxVal = -100000000;

int dr[] = {0, 1};
int dc[] = {1, 0};

void DFS(int row, int col, int val, int type) {
    if (row == N - 1 && col == N - 1) {
        if (type == MIN) 
            minVal = min(minVal, val);
        else if (type == MAX) 
            maxVal = max(maxVal, val);
        return;
    }

    // 현재 위치가 연산자인 경우
    char oper = v[row][col];
    if (oper == '+' || oper == '-' || oper == '*') {
        for (int i = 0; i < 2; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N)
                continue;

            int result;
            int firstVal = val;
            int secondVal = v[nextRow][nextCol] - '0';

            if (oper == '+') 
                result = firstVal + secondVal;
            else if (oper == '-') 
                result = firstVal - secondVal;
            else if (oper == '*') 
                result = firstVal * secondVal;

            if (type == MAX) {
                if (result > dp[nextRow][nextCol]) {
                    dp[nextRow][nextCol] = result;
                    DFS(nextRow, nextCol, result, type);
                }
            }
            else if (type == MIN) {
                if (result < dp[nextRow][nextCol]) {
                    dp[nextRow][nextCol] = result;
                    DFS(nextRow, nextCol, result, type);
                }
            }
        }
    }

    // 현재 위치가 숫자인 경우
    else {
        for (int i = 0; i < 2; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= N)
                continue;
            
            DFS(nextRow, nextCol, val, type);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> v[i][j];

    // max
    dp.assign(N, vector<int>(N, -10000000));
    DFS(0, 0, v[0][0] - '0', MAX);

    // min
    dp.assign(N, vector<int>(N, 10000000));
    DFS(0, 0, v[0][0] - '0', MIN);
    
    cout << maxVal << ' ' << minVal;

    return 0;
}