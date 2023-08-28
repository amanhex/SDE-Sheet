#include <bits/stdc++.h>
using namespace std;

void permute(string& s, vector<string>& res, string& current, vector<int>& map){
  if (current.size() == s.size()){
    res.push_back(current);
    return;
  }
  for (int i = 0; i < s.size(); i++){
    if (!map[i]){
      map[i] = 1;
      current.push_back(s[i]);
      permute(s, res, current, map);
      map[i] = 0;
      current.pop_back();
    }
  }
  return;
}

vector<string> permutationBrute(string& s){
  vector<string> res;
  vector<int> map(s.size(), 0);
  string current = "";
  permute(s, res, current, map);
  return res;
}

int main(){
  string s;
  cin >> s;
  vector<string> res = permutationBrute(s);

  for (auto i : res)
    cout << i << endl;

  return 0;
}
