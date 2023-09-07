#include <bits/stdc++.h>
using namespace std;

void solve(string& s, vector<string>& wordDict, vector<string>& ans, vector<string>& sentence, unordered_map<int, bool>& memo, int start){
  if (start == s.size()){
    string temp = "";
    for (int i = 0; i < sentence.size(); i++){
      temp += sentence[i];
      if (i < sentence.size() - 1)
        temp += " ";
    }
    ans.push_back(temp);
    return;
  }

  // Checking if memo contains the word 
  if (memo[start])
    return;

  for (const string& word : wordDict){
    int len = word.size();
    if (start + len <= s.size() && s.substr(start, len) == word){
      memo[start] = true;
      sentence.push_back(word);
      solve(s, wordDict, ans, sentence, memo, start + len);
      memo[start] = false;
      sentence.pop_back();
    }
  }
  return;
}

vector<string> wordBreak(string& s, vector<string>& wordDict){
  vector<string> ans;
  unordered_map<int, bool> memo;
  vector<string> sentence;
  solve(s, wordDict, ans, sentence, memo, 0);
  return ans;
}

int main(){
  string s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  vector<string> result = wordBreak(s, wordDict);

  for (auto i : result)
    cout << i << ", ";
  cout << endl;
  return 0;
}
