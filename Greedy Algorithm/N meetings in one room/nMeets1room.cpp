#include <bits/stdc++.h>
using namespace std;

int nMeet1Room(vector<int>& startTime, vector<int>& endTime){
  vector<pair<int, int>> meetings;
  for (int i = 0; i < startTime.size(); i++){
    pair<int, int> temp;
    temp.first = endTime[i];
    temp.second = startTime[i];
    meetings.push_back(temp);
  }

  // Sorting the meetings vector so that meetings with smaller end time can be done first
  sort(meetings.begin(), meetings.end());

  int count = 1;
  int lastEndTime = meetings[0].first;
  for (int i = 1; i < meetings.size(); i++){
    if (meetings[i].second > lastEndTime){
      count++;
      lastEndTime = meetings[i].first;
    }
  }
  return count;
}

int main(){
  int size;
  cin >> size;
  vector<int> startTime(size);
  vector<int> endTime(size);
  for (int i = 0; i < size; i++)
    cin >> startTime[i];
  for (int i = 0; i < size; i++)
    cin >> endTime[i];

  int ans = nMeet1Room(startTime, endTime);
  cout << ans << endl;
  return 0;
}
