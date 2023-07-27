#include <bits/stdc++.h>
using namespace std;

// Moore's Voting Algorithm
int majElOp(vector<int> arr){
    int element, count = 0;
    for (int i = 0; i < arr.size(); i++){
        if (count == 0){
            element = arr[i];
            count++;
        }
        else if (arr[i] == element)
            count++;
        else
            count--;
    }
    return element;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int ans = majElOp(arr);
    cout << ans << endl;
    return 0;
}
