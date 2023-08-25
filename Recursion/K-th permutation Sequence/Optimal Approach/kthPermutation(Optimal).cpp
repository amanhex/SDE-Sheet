#include <bits/stdc++.h>
using namespace std;

string kthPermutationOp(int n, int k){
  int factorial = 1;
  vector<int> numbers;
  for (int i = 1; i <= n; i++){
    factorial *= i;
    numbers.push_back(i);
  }
  factorial /= n;
  string ans = "";
  k -= 1;
  while (true){
    ans += numbers[k / factorial] + '0';
    numbers.erase(numbers.begin() + k / factorial);
    if (numbers.size() == 0)
      break;
    k %= factorial;
    factorial /= numbers.size();
  }
  return ans;
}

int main(){
  int n, k;
  cin >> n >> k;
  string res = kthPermutationOp(n, k);
  cout << res << endl;
  return 0;
}
