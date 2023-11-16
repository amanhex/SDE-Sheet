#include <iostream>
#include <stack>
using namespace std;

class Queue {
  private:
    stack<int> input, output;
  public:
    Queue() {};

    void Push(int num){
      input.push(num);
    }
    
    void Pop(){
      if (!output.empty())
        output.pop();
      else if (input.empty())
        cout << "Queue is empty" << endl;
      else{
        while (!input.empty()){
          output.push(input.top());
          input.pop();
        }
        output.pop();
      }
    }

    int Top(){
      if (!output.empty())
        return output.top();
      else if (input.empty()){
        cout << "Queue is empty" << endl;
        return -1;
      }
      else{
        while (!input.empty()){
          output.push(input.top());
          input.pop();
        }
        return output.top();
      }
    }
    
    int Size(){
      if (!output.empty())
        return output.size();
      else
        return input.size();
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
