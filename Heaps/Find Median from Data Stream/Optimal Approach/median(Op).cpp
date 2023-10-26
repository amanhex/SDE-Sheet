#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
  private:
    priority_queue<int> smallHeap; // MAX HEAP (Stores small elements)
    priority_queue<int, vector<int>, greater<int>> largeHeap; // MIN HEAP (Stores large elements than MAX HEAP)
  public:
    MedianFinder() {}
    
    void addNum(int num) {
      if (smallHeap.empty() || num <= smallHeap.top()) {
          smallHeap.push(num);
      } else {
          largeHeap.push(num);
      }

      // Balance the heaps
      if (smallHeap.size() > largeHeap.size() + 1) {
          largeHeap.push(smallHeap.top());
          smallHeap.pop();
      } else if (largeHeap.size() > smallHeap.size()) {
          smallHeap.push(largeHeap.top());
          largeHeap.pop();
      }
    }

    double findMedian() {
      if (smallHeap.size() > largeHeap.size())
        return smallHeap.top() * 1.0;
      return largeHeap.top() + smallHeap.top() / 2.0;
    }
};

int main(){
  MedianFinder obj;
  obj.addNum(1);
  obj.addNum(2);
  cout << obj.findMedian() << " ";
  obj.addNum(3);
  cout << obj.findMedian() << endl;
  return 0;
}
