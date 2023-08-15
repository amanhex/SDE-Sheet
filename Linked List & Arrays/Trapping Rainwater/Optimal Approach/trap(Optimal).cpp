#include <bits/stdc++.h>
using namespace std;

int trapRainwaterOp(vector<int>& nums){
  int res = 0, left = 0, right = nums.size() - 1;
  int maxLeft = 0, maxRight = 0;
  while (left <= right){
    if (nums[left] <= maxRight){
      if (nums[left] < maxLeft)
        res += maxLeft - nums[left];
      else
        maxLeft = max(maxLeft, nums[left]);
      left++;
    }
    else{
      if (nums[right] < maxRight)
        res += maxRight - nums[right];
      else
        maxRight = max(maxRight, nums[right]);
      right--;
    }
  }
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  int ans = trapRainwaterOp(nums);
  cout << ans << endl;
}

