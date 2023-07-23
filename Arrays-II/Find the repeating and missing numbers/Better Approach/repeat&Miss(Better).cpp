//Better Approach: Use Hashing

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissBetter(vector<int> arr){
    int repeat = -1, miss = -1, n = arr.size();
    vector<int> freq(n, 0);
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (int i = 1; i <= n; i++){
        if (freq[i] == 2)
            repeat = i;
        else if (freq[i] == 0)
            miss = i;
        if (repeat != -1 && miss != -1)
            return {repeat, miss};
    }
    return {repeat, miss};
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    vector<int> ans = repeatAndMissBetter(arr);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
