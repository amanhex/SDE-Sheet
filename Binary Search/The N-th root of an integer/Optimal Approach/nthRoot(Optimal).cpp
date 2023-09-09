#include <bits/stdc++.h>
using namespace std;

int func(int mid, int root, int number){
  long long ans = 1;
  for (int i = 1; i <= root; i++){
    ans *= mid;
    if (ans > number) return 2;
  }
  if (ans == number) return 1;
  return 0;
}

int nthRootOp(int root, int number){
  int low = 1, high = number;
  while (low <= high){
    int mid = (low + high) / 2;
    int midN = func(mid, root, number);
    if (midN == 1)
      return mid;
    else if (midN == 0) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int main(){
  int root, number;
  cin >> root >> number;
  int ans = nthRootOp(root, number);
  cout << ans << endl;
  return 0;
}
