#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBrute(vector<int>& nums){
  if (nums.size() < 3)
    return {{}};
  set<vector<int>> st;
  for (int i = 0; i < nums.size(); i++){
    for (int j = i + 1; j < nums.size(); j++){
      for (int k = j + 1; k < nums.size(); k++){
        if (nums[i] + nums[j] + nums[k] == 0){
          vector<int> temp = {nums[i], nums[j], nums[k]};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
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
  vector<vector<int>> res = threeSumBrute(nums);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
