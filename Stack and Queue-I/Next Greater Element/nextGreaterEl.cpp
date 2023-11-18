#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterEl(vector<int>& nums){
  int n = nums.size();
  vector<int> nge(n, -1);
  stack<int> st;
  for (int i = 2 * n - 1; i >= 0; i--){
    while (!st.empty() && nums[i % n] >= st.top())
      st.pop();
    if (i < n){
      if (!st.empty()) nge[i] = st.top();
    }
    st.push(nums[i % n]);
  }
  return nge;
}

int main(){
  vector<int> nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
  vector<int> output = nextGreaterEl(nums);

  for (auto i : output)
    cout << i << " ";
  cout << endl;
  return 0;
}
