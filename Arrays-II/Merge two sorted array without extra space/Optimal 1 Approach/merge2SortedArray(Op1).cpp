#include <bits/stdc++.h>
using namespace std;

void mergeOp1(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int left = n - 1, right = 0;
    while (left >= 0 && right < m){
        if (arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
            break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main(){
    int size1, size2;
    cin >> size1 >> size2;
    vector<int> arr1(size1, 0);
    vector<int> arr2(size2, 0);

    // Input sorted arrays only
    for (int i = 0; i < size1; i++)
        cin >> arr1[i];
    for (int i = 0; i < size2; i++)
        cin >> arr2[i];
    cout << endl;

    mergeOp1(arr1, arr2);

    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << " ";
}
