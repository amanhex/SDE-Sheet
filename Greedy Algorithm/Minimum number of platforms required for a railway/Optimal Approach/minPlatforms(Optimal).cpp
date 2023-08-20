#include <bits/stdc++.h>
using namespace std;

int minPlatformsOp(vector<int>& arrTime, vector<int>& depTime){
  sort(arrTime.begin(), arrTime.end());
  sort(depTime.begin(), depTime.end());
  int ans = 1, i = 1, j = 0, count = 1;
  while(i < arrTime.size() && j < depTime.size()){
    if (arrTime[i] <= depTime[j]){
      count++;
      i++;
    }
    else {
      count--;
      j++;
    }
    ans = max(ans, count);
  }
  return ans;
}

int main(){
  int size;
  cin >> size;
  vector<int> arrTime(size);
  vector<int> depTime(size);
  for (int i = 0; i < size; i++)
    cin >> arrTime[i];
  for (int i = 0; i < size; i++)
    cin >> depTime[i];

  int res = minPlatformsOp(arrTime, depTime);
  cout << "Number of Platforms required : " << res << endl;
  return 0;
}
