#include <iostream>
#include <queue>
using namespace std;

class Stack{
  queue<int> q1, q2;

public:
  // Push element onto stack
  void push(int x){
     q2.push(x);

         while (!q1.empty()){
          q2.push(q1.front());
          q1.pop();
     }

         swap(q1, q2);
 }

     // Remove top element
     void pop(){
        if (q1.empty()){
           cout << "Stack is empty!" << endl;
           return;
     }

         q1.pop();
 }

     // Return top element
     int top(){
        if (q1.empty()){
           cout << "Stack is empty!" << endl;
           return -1;
        }

            return q1.front();
    }

        // Check if stack is empty
        bool empty(){
           return q1.empty();
  }
};

int main(){
   Stack s;

        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Top element: " << s.top() << endl;

        s.pop();
        cout << "Top after pop: " << s.top() << endl;

        cout << "Isstackempty?"
          << (s.empty() ? "Yes" : "No") << endl;

        return 0;
}
