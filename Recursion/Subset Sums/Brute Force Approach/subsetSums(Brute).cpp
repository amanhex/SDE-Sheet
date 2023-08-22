#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSumsBrute(vector<int>& nums){
  vector<int> res;
  int n = nums.size();
  int sub_cnt = 1 << n;
  for (int mask = 0; mask < sub_cnt; mask++){
    int sum = 0;
    for (int i = 0; i < n; i++){
      if (mask & (1 << i))
        sum += nums[i];
    }
    res.push_back(sum);
  }
  sort(res.begin(), res.end());
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  vector<int> res = subsetSumsBrute(nums);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
