// Better Approach: Count the number of 0s, 1s and 2s and place them in the array at their appropriate place

#include <bits/stdc++.h>
using namespace std;

void sortBetter(vector<int>& arr){
    int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == 0)
                count0++;
            else if (arr[i] == 1)
                count1++;
            else
                count2++;
        }
        int i = 0;
        while (i < count0){
            arr[i] = 0;
            i++;
        }
        while (i < count0 + count1){
            arr[i] = 1;
            i++;
        }
        while (i < arr.size()){
            arr[i] = 2;
            i++;
        }
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    sortBetter(arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
