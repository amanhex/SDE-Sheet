#include <bits/stdc++.h>
using namespace std;

vector<int> majElBetter(vector<int> arr){
    int n = arr.size();
    int minCount = (int)(n / 3) + 1;
    unordered_map<int, int> map;
    vector<int> res;
    for (int i = 0; i < n; i++){
        map[arr[i]]++;
        if (map[arr[i]] == minCount)
            res.push_back(arr[i]);
        if (res.size() == 2)
            res.push_back(arr[i]);
    }
    return res;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    vector<int> ans = majElBetter(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
