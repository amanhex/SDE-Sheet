#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
  stack<char> st;
  int n = s.length();
  if (n % 2 == 1) return false;

  for (int i = 0; i < n; i++){
    if (s[i] == '(' || s[i] == '[' || s[i] == '{')
      st.push(s[i]);
    else{
      if (st.empty()) return false;
      else if ((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}'))
        st.pop();
      else
        return false;
    }
  }
  return st.empty();
}

int main(){
  string s = "{([({})])}";
  if (isValid(s))
    cout << "True" << endl;
  else 
    cout << "False" << endl;
  return 0;
}
