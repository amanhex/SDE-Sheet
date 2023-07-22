#include <bits/stdc++.h>
using namespace std;

void mergeBrute(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> arr3;
    int left = 0, right = 0;
    while (left < n && right < m){
        if (arr1[left] < arr2[right]){
            arr3.push_back(arr1[left]);
            left++;
        }
        else{
            arr3.push_back(arr2[right]);
            right++;
        }
    }
    while (left < n){
        arr3.push_back(arr1[left]);
        left++;
    }
    while (right < m){
        arr3.push_back(arr2[right]);
        right++;
    }

    for (int i = 0; i < arr3.size(); i++){
        if (i < n)
            arr1[i] = arr3[i];
        else
            arr2[i - n] = arr3[i];
    }
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

    mergeBrute(arr1, arr2);

    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << " ";
}
