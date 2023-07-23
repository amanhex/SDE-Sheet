// Solution 1: Using sort()

#include <bits/stdc++.h>
using namespace std;

int duplicateBrute(vector<int> arr){
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] == arr[i - 1])
            return arr[i];
    }
    return 0;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    int ans = duplicateBrute(arr);

    cout << ans;
    return 0;
}
