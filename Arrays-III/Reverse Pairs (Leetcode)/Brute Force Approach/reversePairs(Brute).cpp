#include <bits/stdc++.h>
using namespace std;

int reversePairsBrute(vector<int>& nums){
    int n = nums.size(), count = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if ((long long)nums[i] > 2 * (long long)nums[j])
                count++;
        }
    }
    return count;
}

int main(){
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = reversePairsBrute(nums);
    cout << ans << endl;
    return 0;
}
