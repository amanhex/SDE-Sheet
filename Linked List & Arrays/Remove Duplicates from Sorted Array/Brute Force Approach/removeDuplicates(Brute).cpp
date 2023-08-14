#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesBrute(vector<int>& nums){
  vector<int> temp;
  temp.push_back(nums[0]);
  for (int i = 1; i < nums.size(); i++){
    if (nums[i] == nums[i - 1])
      continue;
    else
     temp.push_back(nums[i]);
  }
  for (int i = 0; i < temp.size(); i++)
    nums[i] = temp[i];
  return temp.size();
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];
  int newSize = removeDuplicatesBrute(nums);

  // Displaying the array
  for (int i = 0; i < newSize; i++)
    cout << nums[i] << " ";
  cout << endl;
  return 0;
}
