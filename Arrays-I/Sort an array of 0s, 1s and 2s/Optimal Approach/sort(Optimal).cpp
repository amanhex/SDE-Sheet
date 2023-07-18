// Optimal Approach: Use Dutch National Flag Algorithm

#include <bits/stdc++.h>
using namespace std;

void sortOptimal(vector<int>& arr){
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high){
        if (arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
        else
            mid++;
    }
    return;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    sortOptimal(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
