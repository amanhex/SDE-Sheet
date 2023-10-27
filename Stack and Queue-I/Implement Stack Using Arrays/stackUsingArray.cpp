#include <iostream>
using namespace std;

class myStack {
  private:
    int size;
    int top;
    int *arr;
  public:
    myStack() {
      size = 1000;
      top = -1;
      arr = new int[size];
    }

    void push(int num){
      top++;
      if (top < size)
        arr[top] = num;
      else
       cout << "Stack full" << endl;
    }

    void pop(){
      if (top == -1)
        cout << "Stack is empty" << endl;
      else
        top--;
    }

    int Top(){
      if (top != -1)
        return arr[top];
      else
        return -1;
    }
    
    int stackSize(){
      return top + 1;
    }

    bool isEmpty(){
      return top == -1;
    }
};

int main(){
  myStack s;
  s.push(6);
  s.push(3);
  s.push(7);
  while (!s.isEmpty()){
    cout << s.Top() << " ";
    s.pop();
  }
  cout << endl;
  s.pop();
  cout << s.stackSize() << endl;
  return 0;
}
