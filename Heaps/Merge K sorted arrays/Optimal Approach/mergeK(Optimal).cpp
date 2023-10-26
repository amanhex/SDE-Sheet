#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKOp(vector<vector<int>>& kArrays){
  vector<int> ans;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  for (int i = 0; i < kArrays.size(); i++)
    pq.push({kArrays[i][0], {i, 0}});

  while (!pq.empty()){
    auto top = pq.top();
    int i = top.second.first;
    int j = top.second.second;
    pq.pop();
    if (j + 1 < kArrays[i].size())
      pq.push({kArrays[i][j + 1], {i, j + 1}});

    ans.push_back(top.first);
  }
  return ans;
}

int main(){
  vector<vector<int>> kArrays = {
    {3, 5, 9},
    {1, 2, 3, 4}
  };

  vector<int> ans = mergeKOp(kArrays);

  for (auto i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}
