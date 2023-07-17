// Solution 3: Using observation to find break point and calculating the result

#include <bits/stdc++.h>
using namespace std;

void swapp(vector<int>& arr, int i, int index){
    int temp = arr[i];
    arr[i] = arr[index];
    arr[index] = temp;
    return;
}

void nextPermutationSol3(vector<int>& arr){
    int n = arr.size(), index = -1;
    for (int i = n - 2; i >= 0; i--){
        if (arr[i] < arr[i + 1]){
            index = i;
            break;
        }
    }
    if (index == -1){
        reverse(arr.begin(), arr.end());
        return;
    }
    int nextGreater = -1;
    for (int i = n - 1; i >= index; i--){
        if (arr[i] > arr[index]){
            nextGreater = i;
            break;
        }
    }
    swapp(arr, nextGreater, index);
    reverse(arr.begin() + index + 1, arr.end());
    return;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    nextPermutationSol3(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
