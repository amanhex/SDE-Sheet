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

int maxDistCowsOp(vector<int>& stalls, int cows){
  sort(stalls.begin(), stalls.end());
  int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
  while (low <= high){
    int mid = low + (high - low) / 2;
    if (isAllocatable(stalls, cows, mid)) low = mid + 1;
    else high = mid - 1;
  }
  return low - 1;
}

int main(){
  int size, cows;
  cin >> size >> cows;
  vector<int> stalls(size);
  for (int i = 0; i < size; i++)
    cin >> stalls[i];

  int ans = maxDistCowsOp(stalls, cows);
  cout << ans << endl;
  return 0;
}
