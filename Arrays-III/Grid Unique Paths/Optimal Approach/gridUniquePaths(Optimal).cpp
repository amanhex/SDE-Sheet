// Optimal Approach: Uses Combinations

#include <bits/stdc++.h>
using namespace std;

int uniquePathsOp(int m, int n){
    int minn = min(m, n);
    int N = m + n - 2;
    double smallAns1 = 1, smallAns2 = 1;
    for (int i = 1; i <= minn; i++){
        smallAns1 *= N;
        smallAns2 *= i;
        N--;
    }
    return (int)(smallAns1 / smallAns2);
}

int main(){
    int m, n;
    cin >> m >> n;

    int ans = uniquePathsOp(m, n);
    cout << ans << endl;
    return 0;
}
