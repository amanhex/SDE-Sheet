#include <bits/stdc++.h>
using namespace std;

struct Activity{
  int startTime;
  int endTime;
  int pos;
};

bool static comparision(Activity a, Activity b){
  if (a.endTime < b.endTime) return true;
  else if (a.endTime > b.endTime) return false;
  else return a.pos < b.pos;
}

vector<int> activity(vector<int>& sTime, vector<int>& eTime){
  int n = sTime.size();
  Activity meetings[n];

  for (int i = 0; i < n; i++){
    meetings[i].startTime = sTime[i];
    meetings[i].endTime = eTime[i];
    meetings[i].pos = i + 1;
  }
  
  sort(meetings, meetings + n, comparision);

  vector<int> order;
  int lastEndTime = meetings[0].endTime;
  order.push_back(meetings[0].pos);
  for (int i = 1; i < n; i++){
    if (meetings[i].startTime > lastEndTime){
      lastEndTime = meetings[i].endTime;
      order.push_back(meetings[i].pos);
    }
  }
  return order;
}

int main(){
  int size;
  cin >> size;
  vector<int> startTime(size);
  vector<int> endTime(size);
  for (int i = 0; i < size; i++)
    cin >> startTime[i] >> endTime[i];
  vector<int> res = activity(startTime, endTime);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
  return 0;
}
