#include <bits/stdc++.h>
using namespace std;

// This approach uses bit masking technique to produce the subsets while storing it into a set to remove duplicate subsets
vector<vector<int>> subset2Brute1(vector<int>& nums){
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int sub_cnt = 1 << n;
  set<vector<int>> st;
  for (int mask = 0; mask < sub_cnt; mask++){
    vector<int> temp;
    for (int i = 0; i < n; i++){
      if (mask & (1 << i))
        temp.push_back(nums[i]);
    }
    st.insert(temp);
  }
  vector<vector<int>> res(st.begin(), st.end());
  return res;
}

// This approach uses recursion to produce all subsets while storing them into a set to remove duplicate subsets
void subset2Helper(vector<int>& nums, vector<int> currSubset, set<vector<int>>& st2, int index){
  if (index == nums.size()){
    sort(currSubset.begin(), currSubset.end());
    st2.insert(currSubset);
    return;
  }
  currSubset.push_back(nums[index]);
  subset2Helper(nums, currSubset, st2, index + 1);
  currSubset.pop_back();
  subset2Helper(nums, currSubset, st2, index + 1);
  return;
}

vector<vector<int>> subset2Brute2(vector<int>& nums){
  set<vector<int>> st2;
  vector<int> currSubset;
  subset2Helper(nums, currSubset, st2, 0);
  vector<vector<int>> res(st2.begin(), st2.end());
  return res;
}

int main(){
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  vector<vector<int>> res = subset2Brute2(nums);

  for (int i = 0; i < res.size(); i++){
    for (int j = 0; j < res[i].size(); j++)
      cout << res[i][j] << " ";
    cout << endl;
  }

  return 0;
}
