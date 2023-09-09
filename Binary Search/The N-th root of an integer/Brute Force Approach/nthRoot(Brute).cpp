#include <bits/stdc++.h>
using namespace std;

long long func(int number, int exp){
  if (number == 1)
    return 1;
  long long ans = 1;
  long long base = number;
  while (exp > 0){
    if (exp % 2){
      exp--;
      ans *= base;
    }
    else{
      exp /= 2;
      base *= base;
    }
  }
  return ans;
}

int nthRootBrute(int root, int number){
  for (int i = 1; i <= number; i++){
    long long val = func(i, root);
    if (val == number * 1ll)
      return i;
    else if (val > number * 1ll)
      break;
  }
  return -1;
}

int main(){
  int root, number;
  cin >> root >> number;

  int ans = nthRootBrute(root, number);
  cout << ans << endl;
  return 0;
}
