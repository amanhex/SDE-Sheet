// Optimal 1 Approach: Using Math

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissOp1(vector<int> arr){
    long long n = arr.size();
    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    //S-Sn = X-Y:
    long long val1 = S - SN;
    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    vector<int> ans = repeatAndMissOp1(arr);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
