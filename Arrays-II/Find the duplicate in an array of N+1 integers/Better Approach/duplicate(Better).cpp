// Solution 2: Using a frequency array to keep track of frequency (HashMap can also be used)

#include <bits/stdc++.h>
using namespace std;

int duplicateBetter(vector<int>& arr){
    int n = arr.size();
    vector<int> freq(n, 0);
    for (int i = 0; i < n; i++){
        if (freq[arr[i] == 0])
            freq[arr[i]]++;
        else
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
    
    int ans = duplicateBetter(arr);

    cout << ans;
    return 0;
}
