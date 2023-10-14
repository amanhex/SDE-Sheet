#include <bits/stdc++.h>
using namespace std;

// Max Heap Implementation
class heap {
  public:
    vector<int> arr;
    
    heap() {
      arr.push_back(-1);
    }

    void insert(int val) {
      arr.push_back(val);
      int index = arr.size() - 1;
      while (index > 1){
        int parent = index / 2;
        if (arr[parent] < arr[index]){
          swap(arr[parent], arr[index]);
          index = parent;
        }
        else return;
      }
    }

    void deleteFromHeap(){
      if (arr.size() == 0) return;
      arr[1] = arr[arr.size() - 1];
      arr.pop_back();

      // Propagate the root node to its right position
      int i = 1;
      while (i < arr.size() - 1){
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        if (leftChild < arr.size() - 1 && arr[i] < arr[leftChild]){
          swap(arr[i], arr[leftChild]);
          i = leftChild;
        }
        else if (rightChild < arr.size() - 1 && arr[i] < arr[rightChild]){
          swap(arr[i], arr[rightChild]);
          i = rightChild;
        }
        else return;
      }
    }

    void display(){
      for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
      cout << endl;
    }
    
    void heapifyMax(vector<int>& arr, int n, int i){
      int largest = i;
      int left = i * 2 + 1, right = 2 * i + 2;
      if (left < n && arr[largest] < arr[left])
        largest = left;
      if (right < n && arr[largest] < arr[right])
        largest = right;
      if (largest != i){
        swap(arr[largest], arr[i]);
        heapifyMax(arr, n, largest);
      }
    }
};
