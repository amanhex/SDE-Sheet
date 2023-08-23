#include <bits/stdc++.h>
using namespace std;

void subset2Helper(vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& res, int index){
  res.push_back(currSubset);
  for (int i = index; i < nums.size(); i++){
    if (i != index && nums[i] == nums[i - 1])
      continue;
    currSubset.push_back(nums[i]);
    subset2Helper(nums, currSubset, res, i + 1);
    currSubset.pop_back();
  }
  return;
}

vector<vector<int>> subset2Op(vector<int>& nums){
  sort(nums.begin(), nums.end());
  vector<int> currSubset;
  vector<vector<int>> res;
  subset2Helper(nums, currSubset, res, 0);
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  vector<vector<int>> res = subset2Op(nums);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}
