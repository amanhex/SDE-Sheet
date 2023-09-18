#include <bits/stdc++.h>
using namespace std;

int searchRotatedBrute(vector<int>& nums, int target){
  for (int i = 0; i < nums.size(); i++){
    if (nums[i] == target)
      return i;
  }
  return -1;
}

int main(){
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  cout << searchRotatedBrute(arr, target) << endl;
  return 0;
}
