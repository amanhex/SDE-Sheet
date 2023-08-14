#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesOp(vector<int>& nums){
  int j = 1;
  for (int i = 1; i< nums.size(); i++){
    if (nums[i] != nums[i - 1])
      nums[j++] = nums[i];
  }
  return j;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];
  int newSize = removeDuplicatesOp(nums);

  // Displaying the array
  for (int i = 0; i < newSize; i++)
    cout << nums[i] << " ";
  cout << endl;
  return 0;
}
