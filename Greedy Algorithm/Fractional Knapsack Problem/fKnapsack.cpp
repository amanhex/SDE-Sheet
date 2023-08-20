#include <bits/stdc++.h>
using namespace std;

struct Item{
  int value;
  int weight;
};

bool static comparision(Item a, Item b){
  double a1 = (double)a.value / (double)a.weight;
  double b1 = (double)b.value / (double)b.weight;
  return a1 > b1;
}

double fKnapsack(vector<Item>& arr, int wKnapsack){
  sort(arr.begin(), arr.end(), comparision);
  int currWeight = 0;
  double finalValue = 0.0;
  for (int i = 0; i < arr.size(); i++){
    if (currWeight + arr[i].weight <= wKnapsack){
      currWeight += arr[i].weight;
      finalValue += arr[i].value;
    }
    else{
      int remain = wKnapsack - currWeight;
      finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
      break;
    }
  }
  return finalValue;
}

int main(){
  int size, wKnapsack;
  cin >> size >> wKnapsack;
  vector<Item> arr(size);
  for (int i = 0; i < size; i++)
    cin >> arr[i].value >> arr[i].weight;
  double ans = fKnapsack(arr, wKnapsack);
  cout << ans << endl;
  return 0;
}
