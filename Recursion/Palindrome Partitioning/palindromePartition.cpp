#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string input, int start, int end){
  while (start < end){
    if (input[start] != input[end])
      return false;
    start++;
    end--;
  }
  return true;
}

void genSubstring(string input, vector<vector<string>>& res, vector<string>& currSubstring, int index){
  if (index == input.size()){
    res.push_back(currSubstring);
    return;
  }

  for (int i = index; i < input.size(); i++){
    if (isPalindrome(input, index, i)){
      currSubstring.push_back(input.substr(index, i - index + 1));
      genSubstring(input, res, currSubstring, i + 1);
      currSubstring.pop_back();
    }
  }
  return;
}

vector<vector<string>> palindromePartition(string input){
  vector<vector<string>> res;
  vector<string> currSubstring;
  genSubstring(input, res, currSubstring, 0);
  return res;
}

int main(){
  string input;
  cin >> input;
  cout << endl;

  vector<vector<string>> res = palindromePartition(input);

  cout << "[";
  for (auto i: res) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}
