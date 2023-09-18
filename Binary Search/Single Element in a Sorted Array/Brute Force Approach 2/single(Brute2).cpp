#include <bits/stdc++.h>
using namespace std;

// Using XOR
int singleBrute2(vector<int>& nums){
  int xr = 0;
  for (int i = 0; i < nums.size(); i++)
    xr ^= nums[i]; 
  return xr;
}

int main(){
  int size;
  cin >> size;
  vector<int> arr(size);
  cout << "Frequency of every element should be twice expect for a single element" << endl;
  for (int i = 0; i < size; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  cout << singleBrute2(arr) << endl;
  return 0;
}
