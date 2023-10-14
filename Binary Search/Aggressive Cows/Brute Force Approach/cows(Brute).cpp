#include <bits/stdc++.h>
using namespace std;

bool isAllocatable(vector<int>& stalls, int cows, int maxDist){
  int prevStall = stalls[0];
  cows--; // Allocated the 1st cow
  for (int i = 1; i < stalls.size(); i++){
    if (cows == 0) break;
    else if (stalls[i] - prevStall >= maxDist){
      prevStall = stalls[i];
      cows--;
    }
  }
  return cows == 0;
}

int maxDistCowsBrute(vector<int>& stalls, int cows){
  sort(stalls.begin(), stalls.end());
  int maxDist = 1, i = 0, limit = stalls[stalls.size() - 1] - stalls[0];
  while (i <= limit){
    if (isAllocatable(stalls, cows, maxDist)) maxDist++, i++;
    else break;
  }
  return maxDist - 1;
}

int main(){
  int size, cows;
  cin >> size >> cows;
  vector<int> stalls(size);
  for (int i = 0; i < size; i++)
    cin >> stalls[i];

  int ans = maxDistCowsBrute(stalls, cows);
  cout << ans << endl;
  return 0;
}
