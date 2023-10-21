#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumComBrute(vector<int>& A, vector<int>& B, int C){
  priority_queue<int> pq;
  for (int i = 0; i < A.size(); i++){
    for (int j = 0; j < B.size(); j++){
      int sum = A[i] + B[j];
      pq.push(sum);
    }
  }

  vector<int> res;
  while (C--){
    res.push_back(pq.top());
    pq.pop();
  }

  return res;
}

int main(){
  int size, C;
  cin >> size >> C;
  vector<int> A(size);
  vector<int> B(size);

  for (int i = 0; i < size; i++)
    cin >> A[i];
  for (int i = 0; i < size; i++)
    cin >> B[i];

  vector<int> ans = maxSumComBrute(A, B, C);
  for (auto i : ans)
    cout << i << endl;
  return 0;
}
