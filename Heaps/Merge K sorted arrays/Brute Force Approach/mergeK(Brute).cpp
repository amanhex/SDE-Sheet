#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKBrute(vector<vector<int>>& kArrays){
  vector<int> ans;
  for (int i = 0; i < kArrays.size(); i++){
    for (int j = 0; j < kArrays[i].size(); j++)
      ans.push_back(kArrays[i][j]);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main(){
  vector<vector<int>> kArrays = {
    {3, 5, 9},
    {1, 2, 3, 4}
  };

  vector<int> ans = mergeKBrute(kArrays);

  for (auto i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}
