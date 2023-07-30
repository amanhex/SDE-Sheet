// Optimal Approach: Using HashSet

#include <bits/stdc++.h>
using namespace std;

int longConsSeqOp(vector<int>& nums){
    if (nums.empty())
        return 0;
    unordered_set<int> st;
    int longest = 1;
    for (auto i : nums)
        st.insert(i);
    for (auto it : st){
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
        cin >> nums[i];
    int ans = longConsSeqOp(nums);
    cout << ans << endl;
    return 0;
}
