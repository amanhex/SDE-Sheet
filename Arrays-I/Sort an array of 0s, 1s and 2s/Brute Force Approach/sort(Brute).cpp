// Brute Force Approach: Use inbuilt sort function or any other sorting algorithm to sort the array

#include <bits/stdc++.h>
using namespace std;

void sortBrute(vector<int>& arr){
    sort(arr.begin(), arr.end());
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    sortBrute(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
