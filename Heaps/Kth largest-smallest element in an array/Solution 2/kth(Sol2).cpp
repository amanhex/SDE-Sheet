// Using Heaps

#include <bits/stdc++.h>
using namespace std;

pair<int, int> kthMinMaxSol2(vector<int>& arr, int k){
  if (k > arr.size()) return make_pair(-1, -1);
  priority_queue<int> maxPq;
  priority_queue<int, vector<int>, greater<int>> minPq;

  int maxEl, minEl;
  for (int i = 0; i < arr.size(); i++){
    maxPq.push(arr[i]);
    minPq.push(arr[i]);
  }

  while (k-- != 1){
    maxPq.pop();
    minPq.pop();
  }
  minEl = minPq.top();
  maxEl = maxPq.top();

  return make_pair(minEl, maxEl);
}

int main(){
  int size, k;
  cin >> size >> k;
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
    cin >> arr[i];

  pair<int, int> ans = kthMinMaxSol2(arr, k);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
