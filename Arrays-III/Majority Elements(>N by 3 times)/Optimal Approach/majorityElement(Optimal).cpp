#include <bits/stdc++.h>
using namespace std;

vector<int> majElOp(vector<int> arr){
    int count1 = 0, count2 = 0, element1, element2;
    for (int i = 0; i < arr.size(); i++){
        if (count1 == 0 && element2 != arr[i]){
            element1 = arr[i];
            count1++;
        }
        else if (count2 == 0 && element1 != arr[i]){
            element2 = arr[i];
            count2++;
        }
        else if (arr[i] == element1)
            count1++;
        else if (arr[i] == element2)
            count2++;
        else
            count1--, count2--;
    }
    count1 = 0, count2 = 0;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++){
        if (element1 == arr[i])
            count1++;
        if (element2 == arr[i])
            count2++;
    }
    int minCount = (int) (arr.size() / 3) + 1;
    if (count1 >= minCount)
        res.push_back(element1);
    if (count2 >= minCount)
        res.push_back(element2);
    return res;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    vector<int> ans = majElOp(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
} 
