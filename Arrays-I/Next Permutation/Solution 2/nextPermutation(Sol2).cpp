// Solution 2: Just use the inbuilt STL function next_permutation to find the answer

#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& arr){
    next_permutation(arr.begin(), arr.end());
    return;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    permute(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
