// Optimal Approach: Use Hashing to store the previous sum with their indices

#include <bits/stdc++.h>
using namespace std;

int largestSubArrKOp(vector<int>& nums, int k){
    int maxLength = 0, sum = 0;
    unordered_map<int, int> prefixSum;
    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if (sum == k)
            maxLength = i + 1;
        if (prefixSum.count(sum - k)){
            int length = i - prefixSum[sum - k];
            maxLength = max(maxLength, length);
        }
        else
            prefixSum[sum] = i;
    }
    return maxLength;
}

int main(){
    int size, k;
    cin >> size >> k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = largestSubArrKOp(nums, k);
    cout << ans << endl;
    return 0;
}
