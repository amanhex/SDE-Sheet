#include <bits/stdc++.h>
using namespace std;

int largestSubArrKBrute(vector<int>& nums, int k){
    int length = 0;
    for (int i = 0; i < nums.size(); i++){
        int sum = 0;
        for (int j = i; j < nums.size(); j++){
            sum += nums[j];
            if (sum == k)
                length = max(length, j - i + 1);
        }
    }
    return length;
}

int main(){
    int size, k;
    cin >> size >> k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = largestSubArrKBrute(nums, k);
    cout << ans << endl;
    return 0;
}
