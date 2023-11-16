#include <iostream>
#include <stack>
using namespace std;

class Queue {
  private:
    stack<int>s1, s2;
  public:
    Queue() {}

    void Push(int num){
      while (!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
      s1.push(num);
      while (!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }
    }

    void Pop(){
      s1.pop();
    }

    int Top(){
      if (s1.empty()){
        cout << "Queue is empty" << endl;
        return -1;
      }
      return s1.top();
    }
    
    int Size(){
      return s1.size();
    }
};

int main(){
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << q.Top() << endl;
  q.Pop();
  q.Push(5);
  cout << q.Top() << endl;
  cout << q.Size() << endl;
}
