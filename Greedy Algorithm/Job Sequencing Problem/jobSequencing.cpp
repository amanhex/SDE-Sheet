#include <bits/stdc++.h>
using namespace std;

struct Job{
  int id;
  int dead;
  int profit;
};

bool static comparision(Job a, Job b){
  return a.profit > b.profit;
}

pair<int, int> jobSequence(vector<Job>& jobs){
  sort(jobs.begin(), jobs.end(), comparision);
  int maxDeadline = jobs[0].dead;

  // Findind the maxDeadline to create an array of slots which store the job id performed on a given day
  for (int i = 1; i < jobs.size(); i++)
    maxDeadline = max(maxDeadline, jobs[i].dead);

  vector<int> slot(maxDeadline + 1, -1);

  int maxProfit = 0, count = 0;
  for (int i = 0; i < jobs.size(); i++){
    for (int j = jobs[i].dead; j > 0; j--){
      if (slot[j] == -1){
        slot[j] = jobs[j].id;
        count++;
        maxProfit += jobs[i].profit;
        break;
      }
    }
  }
  return make_pair(count, maxProfit);
}

int main(){
  int size;
  cin >> size;
  vector<Job> jobs(size);
  for (int i = 0; i < size; i++)
    cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
  cout << endl;
  pair<int, int> res = jobSequence(jobs);
    cout << res.first << " " << res.second << endl;
  return 0;
}
