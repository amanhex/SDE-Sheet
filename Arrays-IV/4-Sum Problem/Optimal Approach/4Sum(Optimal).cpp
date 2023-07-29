#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumOp(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size(); j++){
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = nums.size() - 1;
            while (k < l){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while (k < l && nums[k] == nums[k + 1])
                        k++;
                    while (k < l && nums[l] == nums[l - 1])
                        l--;
                    k++, l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return ans;
}

int main(){
    int size, target;
    cin >> size >> target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    vector<vector<int>> ans = fourSumOp(nums, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
