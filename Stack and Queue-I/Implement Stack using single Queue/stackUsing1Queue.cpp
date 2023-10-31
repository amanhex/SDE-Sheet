#include <iostream>
using namespace std;

class myQueue {
  private:
    int *arr;
    int start, end, currSize, maxSize;
  public:
    myQueue(){
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

    myQueue (int maxSize) {
      this -> maxSize = maxSize;
      arr = new int[maxSize];
      start = -1;
      end = -1;
      currSize = 0;
    }
    
    void push(int num){
      if (currSize == maxSize){
        cout << "Queue is full" << endl;
        return;
      }
      if (end == -1){
        start = 0;
        end = 0;
      }
      else
        end = (end + 1) % maxSize;
      arr[end] = num;
      currSize++;
    }
    
    void pop(){
      if (start == -1){
        cout << "Queue is empty" << endl;
        return;
      }
      if (currSize == 1){
        start = -1;
        end = -1;
      }
      else 
        start = (start + 1) % maxSize;
      currSize--;
    }

    int top(){
      if (start == -1){
        cout << "Queue is empty" << endl;
        return -1;
      }
      return arr[start];
    }

    int size(){
      return currSize;
    }
};

int main(){
  myQueue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  while (q.size() != 0){
    cout << q.top() << endl;
    q.pop();
  }
  cout << q.size() << endl;
  return 0;
}
