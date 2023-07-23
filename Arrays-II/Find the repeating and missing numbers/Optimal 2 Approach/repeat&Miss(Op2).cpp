// Optimal 2 Approach: Using XOR

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissOp2(vector<int> arr){
    int n = arr.size();
    int xr = 0;
    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }
    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));
    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((arr[i] & number) != 0)
            one = one ^ arr[i];
        //part of 0 group:
        else
            zero = zero ^ arr[i];
    }
    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0)
            one = one ^ i;
        //part of 0 group:
        else
            zero = zero ^ i;
    }
    // Last step: Identify the numbers:
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == zero) count++;

    if (count == 2) return {zero, one};
    return {one, zero};
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    vector<int> ans = repeatAndMissOp2(arr);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
