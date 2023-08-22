#include <bits/stdc++.h>
using namespace std;

void subsetSumHelper(vector<int>& nums, vector<int>& res, int index, int sum){
  if (index == nums.size()){
    res.push_back(sum);
    return;
  }
  subsetSumHelper(nums, res, index + 1, sum + nums[index]);
  subsetSumHelper(nums, res, index + 1, sum);
  return;
}

vector<int> subsetSumsOp(vector<int>& nums){
  vector<int> res;
  subsetSumHelper(nums, res, 0, 0);
  sort(res.begin(), res.end());
  return res;
}

int main(){
  int size; 
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  vector<int> res = subsetSumsOp(nums);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
