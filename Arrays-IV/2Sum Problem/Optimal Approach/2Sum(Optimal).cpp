// Optimal Approach: Use Hashing

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumOp(vector<int>& nums, int target){
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++){
        int rem = target - nums[i];
        if (map.count(rem))
            return {i, map[rem]};
        map[nums[i]] = i;
    }
    return {};
}

int main(){
    int size, target;
    cin >> size >> target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    vector<int> res = twoSumOp(nums, target);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
