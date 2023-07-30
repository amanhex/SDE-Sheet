// Better Approach: Using Sorting

#include <bits/stdc++.h>
using namespace std;

int longConsSeqBetter(vector<int>& nums){
    if (nums.empty())
        return 0;
    sort(nums.begin(), nums.end());
    int maxLength = 1, length = 1;;
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == nums[i - 1] + 1)
            length++;
        else if (nums[i] == nums[i - 1])
            continue;
        else{
            maxLength = max(length, maxLength);
            length = 1;
        }
    }
    maxLength = max(length, maxLength);
    return maxLength;
}

int main(){
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = longConsSeqBetter(nums);
    cout << ans << endl;
    return 0;
}
