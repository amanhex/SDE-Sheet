#include <bits/stdc++.h>
using namespace std;

int maxCons1(vector<int>& nums){
  int max1 = 0, count = 0;
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] != 1)
      count = 0;
    else{
      count++;
      max1 = max(count, max1);
    }
  }
  return max1;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  // The vector only contains 0 or 1
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  int ans = maxCons1(nums);
  cout << ans << endl;
  return 0;
}
