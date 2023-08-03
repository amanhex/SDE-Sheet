// Optimal Appraoch: Use Hashing

#include <bits/stdc++.h>
using namespace std;

int subArrXorKOp(vector<int>& nums, int k){
    int count = 0, xr = 0;
    unordered_map<int, int> map;
    map[xr]++;
    for (int i = 0; i < nums.size(); i++){
        xr ^= nums[i];
        int x = xr ^ k;
        count += map[x];
        map[xr]++;
    }
    return count;
}

int main(){
    int size, k;
    cin >> size >> k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = subArrXorKOp(nums, k);
    cout << ans << endl;
    return 0;
}
