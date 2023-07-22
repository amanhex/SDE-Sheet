#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int i, int j){
    if (arr1[i] > arr2[j])
        swap(arr1[i], arr2[j]);
}

void mergeOp2(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int gap = (n + m + 1) / 2;

    while (gap > 0) {
        int i = 0, j = gap;
        while (j < n + m) {
            // arr1 & arr1
            if (i < n && j < n)
                swapIfGreater(arr1, arr1, i, j);
            // arr1 & arr2
            else if (i < n && j >= n)
                swapIfGreater(arr1, arr2, i, j - n);
            // arr2
            else
                swapIfGreater(arr2, arr2, i - n, j - n);
            i++, j++;
        }

        if (gap == 1) {
            break;
        }
        gap = (gap + 1) / 2;
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

    mergeOp2(arr1, arr2);

    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " ";
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << " ";
}
