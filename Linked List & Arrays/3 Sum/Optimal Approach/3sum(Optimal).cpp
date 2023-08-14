#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumOp(vector<int>& nums){
  if (nums.size() < 3)
    return {{}};
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  for (int i = 0; i < nums.size(); i++){
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int j = i + 1, k = nums.size() - 1;
    while (j < k){
      if (nums[i] + nums[j] + nums[k] == 0){
        ans.push_back({nums[i], nums[j], nums[k]});
        while (j < k && nums[j + 1] == nums[j])
          j++;
        while (j < k && nums[k - 1] == nums[k])
          k--;
        j++;
        k--;
      }
      else if (nums[i] + nums[j] + nums[k] > 0)
        k--;
      else
       j++;
    }
  }
  return ans;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];
  vector<vector<int>> res = threeSumOp(nums);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
