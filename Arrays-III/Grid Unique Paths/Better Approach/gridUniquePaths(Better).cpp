// Better Approach: Uses Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
    if (i > m - 1 || j > n - 1)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans1 = countPaths(i + 1, j, m, n, dp);
    int ans2 = countPaths(i, j + 1, m, n, dp);
    dp[i][j] = ans1 + ans2;
    return dp[i][j];
}

int uniquePathsBetter(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countPaths(0, 0, m, n, dp);
}

int main(){
    int m, n;
    cin >> m >> n;

    int ans = uniquePathsBetter(m, n);
    cout << ans << endl;
    return 0;
}
