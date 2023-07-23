// Solution 3: Use Linked List Cycle Detection Method

#include <bits/stdc++.h>
using namespace std;

int duplicateOptimal(vector<int> arr){
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    int ans = duplicateOptimal(arr);

    cout << ans;
    return 0;
}
