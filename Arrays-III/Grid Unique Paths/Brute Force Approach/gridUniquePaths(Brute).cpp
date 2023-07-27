// Brute Force Approach: Uses Recursion

#include <bits/stdc++.h>
using namespace std;

int countPaths(int i, int j, int m, int n){
    if (i > m - 1 || j > n - 1)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;
    int ans1 = countPaths(i + 1, j, m, n);
    int ans2 = countPaths(i, j + 1, m, n);
    return ans1 + ans2;
}

int uniquePathsBrute(int m, int n){
    return countPaths(0, 0, m, n);
}

int main(){
    int m, n;
    cin >> m >> n;

    int ans = uniquePathsBrute(m, n);
    cout << ans << endl;
    return 0;
}
