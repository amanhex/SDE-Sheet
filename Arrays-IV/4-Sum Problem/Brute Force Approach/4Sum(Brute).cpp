#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumBrute(vector<int>& nums, int target){
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                for (int l = k + 1; l < n; l++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){
    int size, target;
    cin >> size >> target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    vector<vector<int>> ans = fourSumBrute(nums, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
