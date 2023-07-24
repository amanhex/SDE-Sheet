#include <bits/stdc++.h>
using namespace std;

int countInversionsBrute(vector<int> arr){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size, 0);
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << countInversionsBrute(arr) << endl;
    return 0;
}
