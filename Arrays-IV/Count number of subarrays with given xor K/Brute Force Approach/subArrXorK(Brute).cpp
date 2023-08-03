#include <bits/stdc++.h>
using namespace std;

int subArrXorKBrute(vector<int>& nums, int k){
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        int xorK = 0;
        for (int j = i; j < nums.size(); j++){
            xorK ^= nums[j];
            if (xorK == k)
                count++;
        }
    }
    return count;
}

int main(){
    int size, k;
    cin >> size >> k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = subArrXorKBrute(nums, k);
    cout << ans << endl;
    return 0;
}
