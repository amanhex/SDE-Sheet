#include <bits/stdc++.h>
using namespace std;

int longConsSeqBrute(vector<int>& nums){
    if (nums.empty())
        return 0;
    int maxLength = 1;
    for (int i = 0; i < nums.size(); i++){
        int length = 1, search = nums[i] + 1;
        for (int j = 0; j < nums.size(); j++){
            if (search == nums[j]){
                length++;
                search++;
                j = 0;
            }
        }
        maxLength = max(length, maxLength);
    }
    return maxLength;
}

int main(){
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = longConsSeqBrute(nums);
    cout << ans << endl;
    return 0;
}
