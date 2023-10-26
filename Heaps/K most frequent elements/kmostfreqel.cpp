#include <bits/stdc++.h>
using namespace std;

vector<int> kmostfreqel(vector<int>& nums, int k){
  unordered_map<int, int> map;
  for (auto i : nums)
    map[i]++;

  priority_queue<pair<int, int>> pq;

  for (auto it = map.begin(); it != map.end(); it++)
    pq.push({it -> second, it -> first});

  vector<int> ans;
  while (k--){
    ans.push_back(pq.top().second);
    pq.pop();
  }

  return ans;
}

int main(){
  int size, k;
  cin >> size >> k;
  vector<int> nums(size);
  for (int i = 0; i < size; i++)
    cin >> nums[i];

  vector<int> res = kmostfreqel(nums, k);
  for (auto i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
