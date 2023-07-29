#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumBetter(vector<int>& nums, int target){
    set<vector<int>> setQuads;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            set<long long> st;
            for (int k = j + 1; k < n; k++){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long search = (long long)target - sum;
                if (st.find(search) != st.end()){
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)search};
                    sort(temp.begin(), temp.end());
                    setQuads.insert(temp);
                }
                st.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(setQuads.begin(), setQuads.end());
    return ans;
}

int main(){
    int size, target;
    cin >> size >> target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    vector<vector<int>> ans = fourSumBetter(nums, target);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
