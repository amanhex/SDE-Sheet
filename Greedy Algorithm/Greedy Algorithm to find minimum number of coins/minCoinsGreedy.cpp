#include <bits/stdc++.h>
using namespace std;

int coins(int money){
  int change = 0;
  int coin[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  for (int i = 8; i >= 0; i--){
    while (money >= coin[i]){
      money -= coin[i];
      change++;
    }
  }
  return change;
}

int main(){
  int money;
  cin >> money;
  int count = coins(money);
  cout << count << endl;
  return 0;
}
