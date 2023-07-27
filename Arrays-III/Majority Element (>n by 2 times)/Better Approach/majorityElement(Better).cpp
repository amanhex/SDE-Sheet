#include <bits/stdc++.h>
using namespace std;

int majElBetter(vector<int> arr){
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
        if (map[arr[i]] > arr.size() / 2)
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
    int ans = majElBetter(arr);
    cout << ans << endl;
    return 0;
}
