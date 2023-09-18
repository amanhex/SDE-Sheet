#include <bits/stdc++.h>
using namespace std;

int searchRotatedOp(vector<int>& nums, int target){
  int low = 0, high = nums.size() - 1;
  while (low <= high){
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;
    // Left Half Sorted
    if (nums[low] <= nums[mid]){
      if (nums[low] <= target && nums[mid] >= target)
        high = mid - 1;
      else
        low = mid + 1;
    }
    // Right Half Sorted
    else{
      if (nums[mid] <= target && nums[high] >= target)
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;

  cout << searchRotatedOp(arr, target) << endl;
  return 0;
}
