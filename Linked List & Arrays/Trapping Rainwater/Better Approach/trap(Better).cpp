#include <bits/stdc++.h>
using namespace std;

int trapRainwaterBetter(vector<int>& nums){
  int res = 0;
  vector<int> left(nums.size(), 0);
  vector<int> right(nums.size(), 0);
  int currLeft = 0, currRight = 0;
  for (int i = 0; i < nums.size(); i++){
    currLeft = max(currLeft, nums[i]);
    left[i] = currLeft;
  }
  for (int i = nums.size() - 1; i >= 0; i--){
    currRight = max(currRight, nums[i]);
    right[i] = currRight;
  }
  int j = 0;
  while (j < nums.size()){
    res += min(left[j], right[j]) - nums[j];
    j++;
  }
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  int ans = trapRainwaterBetter(nums);
  cout << ans << endl;
}
