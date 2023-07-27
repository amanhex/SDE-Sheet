#include <bits/stdc++.h>
using namespace std;

vector<int> majElBrute(vector<int> arr){
    vector<int> res;
    for (int i = 0; i < arr.size(); i++){
        if (res.size() == 0 || res[0] != arr[i]){
            int count = 0;
            for (int j = 0; j < arr.size(); j++){
                if (arr[i] == arr[j])
                    count++;
            }
            if (count > arr.size() / 3)
                res.push_back(arr[i]);
        }
        if (res.size() == 2)
            break;
    }
    return res;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    vector<int> ans = majElBrute(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
