#include <bits/stdc++.h>
using namespace std;

int majElBrute(vector<int> arr){
    for (int i = 0; i < arr.size(); i++){
        int count = 0;
        for (int j = 0; j < arr.size(); j++){
            if (arr[i] == arr[j])
                count++;
        }
        if (count > arr.size() / 2)
            return arr[i];
    }
    return -1;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int ans = majElBrute(arr);
    cout << ans << endl;
    return 0;
}
