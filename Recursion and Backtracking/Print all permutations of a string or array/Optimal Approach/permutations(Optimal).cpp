#include <bits/stdc++.h>
using namespace std;

void permute(string& s, vector<string>& res, int index){
  if (index == s.size()){
    res.push_back(s);
    return;
  }
  for (int i = index; i < s.size(); i++){
    swap(s[i], s[index]);
    permute(s, res, index + 1);
    swap(s[i], s[index]);
  }
  return;
}

vector<string> permutationOp(string& s){
  vector<string> res;
  permute(s, res, 0);
  return res;
}

int main(){
  string s;
  cin >> s;
  vector<string> res = permutationOp(s);

  for (auto i : res)
    cout << i << endl;

  return 0;
}
