#include <bits/stdc++.h>
using namespace std;

int trapRainwaterBrute(vector<int>& nums){
  int res = 0;
  for (int i = 0; i < nums.size(); i++){
    int left = 0, right = 0;
    int j = i;
    // Finding left max
    while (j >= 0){
      left = max(left, nums[j]);
      j--;
    }
    // Finding right max
    j = i;
    while (j < nums.size()){
      right = max(right, nums[j]);
      j++;
    }
    res += min(left, right) - nums[i];
  }
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  int ans = trapRainwaterBrute(nums);
  cout << ans << endl;
}
