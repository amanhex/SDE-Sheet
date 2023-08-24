#include <bits/stdc++.h>
using namespace std;

void comSum2Helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& currCombination, int remain, int index){
  if (remain == 0){
    res.push_back(currCombination);
    return;
  }
  else if (remain < 0)
    return;
  // There is no need to check index == nums.size() because this for loop will take care of it
  for (int i = index; i < nums.size(); i++){
    if (i != index && nums[i] == nums[i - 1])
      continue;
    currCombination.push_back(nums[i]);
    comSum2Helper(nums, res, currCombination, remain - nums[i], i + 1);
    currCombination.pop_back();
  }
  return;
}

vector<vector<int>> comSum2(vector<int>& nums, int target){
  vector<vector<int>> res;
  vector<int> currCombination;
  sort(nums.begin(), nums.end());
  comSum2Helper(nums, res, currCombination, target, 0);
  return res;
}

int main(){
  int size, target;
  cin >> size >> target;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];
  cout << endl;

  vector<vector<int>> res = comSum2(nums, target);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }
  return 0;
}
