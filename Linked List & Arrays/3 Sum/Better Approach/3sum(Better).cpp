#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBetter(vector<int>& nums){
  if (nums.size() < 3)
    return {{}};
  set<vector<int>> st;
  for (int i = 0; i < nums.size(); i++){
    set<int> hashset;
    for (int j = i + 1; j < nums.size(); j++){
      int third = -(nums[i] + nums[j]);
      if (hashset.find(third) != hashset.end()){
        vector<int> temp = {nums[i], nums[j], third};
        sort(temp.begin(), temp.end());
        st.insert(temp);
      }
      hashset.insert(nums[j]);
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];
  vector<vector<int>> res = threeSumBetter(nums);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
