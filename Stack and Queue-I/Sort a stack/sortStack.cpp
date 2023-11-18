#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& st, int num){
  if (st.empty() || num > st.top()){
    st.push(num);
    return;
  }

  int n = st.top();
  st.pop();

  sortedInsert(st, num);

  st.push(n);
}

void sortStack(stack<int>& st){
  // Base Case
  if (st.empty()) return;

  int num = st.top();
  st.pop();

  sortStack(st);
  sortedInsert(st, num);
}

int main(){
  stack<int> st;
  st.push(3);
  st.push(5);
  st.push(-1);
  st.push(2);
  st.push(8);
  st.push(7);

  sortStack(st);
  while (!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}
