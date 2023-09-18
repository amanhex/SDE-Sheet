#include <bits/stdc++.h>
using namespace std;

int singleBrute1(vector<int>& nums){
  if (nums.size() == 1)
    return nums[0];
  for (int i = 0; i < nums.size(); i++){
    if (i == 0){
      if (nums[i] != nums[i + 1]) return nums[i];
    }
    else if (i == nums.size() - 1){
      if (nums[i] != nums[i - 1]) return nums[i];
    }
    else{
      if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
    }
  }
  return nums[0];
}

int main(){
  int size;
  cin >> size;
  vector<int> arr(size);
  cout << "Frequency of every element should be twice expect for a single element" << endl;
  for (int i = 0; i < size; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  cout << singleBrute1(arr) << endl;
  return 0;
}
