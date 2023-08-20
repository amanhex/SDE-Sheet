#include <bits/stdc++.h>
using namespace std;

int minPlatformsBrute(vector<int>& arrTime, vector<int>& depTime){
  int ans = 0;
  for (int i = 0; i < arrTime.size(); i++){
    int count = 1;
    for (int j = i + 1; j < depTime.size(); j++){
      if ((depTime[j] >= arrTime[i] && arrTime[j] <= depTime[i]) || (arrTime[i] >= arrTime[j] && arrTime[i] <= depTime[j]))
        count++;
    }
    ans = max(count, ans);
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

  int res = minPlatformsBrute(arrTime, depTime);
  cout << "Number of Platforms required : " << res << endl;
  return 0;
}
