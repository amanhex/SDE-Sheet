#include <bits/stdc++.h>
using namespace std;

void subset2Helper(vector<int>& nums, vector<int>& currSubset, set<vector<int>>& st, int index){
  if (index == nums.size()){
    st.insert(currSubset);
    return;
  }
  currSubset.push_back(nums[index]);
  subset2Helper(nums, currSubset, st, index + 1);
  currSubset.pop_back();
  subset2Helper(nums, currSubset, st, index + 1);
  return;
}

vector<vector<int>> subset2Op(vector<int>& nums){
  sort(nums.begin(), nums.end());
  vector<int> currSubset;
  set<vector<int>> st;
  subset2Helper(nums, currSubset, st, 0);
  vector<vector<int>> res(st.begin(), st.end());
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  vector<vector<int>> res = subset2Op(nums);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}
