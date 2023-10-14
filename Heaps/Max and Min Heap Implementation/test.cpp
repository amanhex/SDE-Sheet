#include <bits/stdc++.h>
#include "heap.h"
using namespace std;

int main(){
  heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);
  h.display();
  h.deleteFromHeap();
  h.display();

  heap a;
  vector<int> arr = {54, 53, 55, 52, 50};
  int n = 5;
  for (int i = n / 2 - 1; i >= 0; i--)
    a.heapifyMax(arr, n, i);

  for (auto i : arr)
    cout << i << " ";
  cout << endl;
  return 0;
}
