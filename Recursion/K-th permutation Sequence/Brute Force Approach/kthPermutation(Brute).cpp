#include <bits/stdc++.h>
using namespace std;

void permutationHelper(string& s, vector<string>& res, int index){
  if (index == s.size()){
    res.push_back(s);
    return;
  }
  for (int i = index; i < s.size(); i++){
    swap(s[index], s[i]);
    permutationHelper(s, res, index + 1);
    swap(s[index], s[i]);
  }
  return;
}

string kthPermutationBrute(int n, int k){
  vector<string> permutation;
  string s;
  for (int i = 1; i <= n; i++)
    s.push_back(i + '0');
  permutationHelper(s, permutation, 0);
  sort(permutation.begin(), permutation.end());
  // don't do return permutation[k - 1]
  auto it = permutation.begin() + (k - 1);
  return *it;
}

int main(){
  int n, k;
  cin >> n >> k;
  string res = kthPermutationBrute(n, k);
  cout << res << endl;
  return 0;
}
