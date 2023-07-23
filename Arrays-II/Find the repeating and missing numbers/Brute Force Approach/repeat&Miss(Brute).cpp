// Brute Force Approach: For each number between 1 to N, we will try to count the occurrence in the given array using linear search.

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatAndMissBrute(vector<int> arr){
    int repeat = -1, miss = -1, n = arr.size();
    for (int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 0; j < n; j++){
            if (arr[j] == i)
                count++;
        }
        if (count == 2)
            repeat = i;
        else if (count == 0)
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

    vector<int> ans = repeatAndMissBrute(arr);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
