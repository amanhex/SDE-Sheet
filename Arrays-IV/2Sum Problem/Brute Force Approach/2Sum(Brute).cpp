#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumBrute(vector<int>& nums, int target){
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

int main(){
    int size, target;
    cin >> size >> target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    vector<int> res = twoSumBrute(nums, target);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
