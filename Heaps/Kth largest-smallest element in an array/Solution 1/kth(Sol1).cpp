// Using sorting

#include <bits/stdc++.h>
using namespace std;

pair<int, int> kthMinMaxSol1(vector<int>& arr, int k){
  sort(arr.begin(), arr.end());
  if (k < arr.size()){
    return make_pair(arr[k - 1], arr[arr.size() - k]);
  }
  return make_pair(-1, -1);
}

int main(){
  int size, k;
  cin >> size >> k;
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
    cin >> arr[i];

  pair<int, int> ans = kthMinMaxSol1(arr, k);
  cout << ans.first << " "<< ans.second << endl;
  return 0;
}
