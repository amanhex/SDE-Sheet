#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumComOp(vector<int>& A, vector<int>& B, int C){
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int n = A.size();
  priority_queue<tuple<int, int, int>> maxHeap;
  set<pair<int, int>> index;

  maxHeap.push({A[n - 1] + B[n - 1], n - 1, n - 1});
  index.insert({n - 1, n - 1});

  vector<int> result;

  while (C--){
    auto [sum, i, j] = maxHeap.top();
    maxHeap.pop();
    result.push_back(sum);

    if (i > 0 && !index.count({i - 1, j})){
      maxHeap.push({A[i - 1] + B[j], i - 1, j});
      index.insert({i - 1, j});
    }

    if (j > 0 && !index.count({i, j - 1})){
      maxHeap.push({A[i] + B[j - 1], i, j - 1});
      index.insert({i, j - 1});
    }
  }

  return result;
}

int main(){
  int size, C;
  cin >> size >> C;
  vector<int> A(size), B(size);

  for (int i = 0; i < size; i++)
    cin >> A[i];
  for (int i = 0; i < size; i++)
    cin >> B[i];

  vector<int> ans = maxSumComOp(A, B, C);
  for (auto i : ans)
    cout << i << endl;
  return 0;
}
