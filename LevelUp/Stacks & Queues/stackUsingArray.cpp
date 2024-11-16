#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top;
        int *arr;
        int capacity;

        Stack(int c){
            capacity  = c;
            top = -1;
            arr = new int[c];
        }

        bool isFull(){
            return top == (capacity - 1);
        }

        void push(int val){
            if(isFull()){
                cout << "Stack is currently full" << endl;
                return;
            }
            arr[++top] = val;
        }

        bool isEmpty(){
            return top == -1;
        }
        
        int stackTop(){
            if(isEmpty()){
                cout << "Stack is currently empty" << endl;
                return -1;
            }
            return arr[top];
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack is currently empty" << endl;
                return;
            }
            top--;
        }
};

int main(){
    Stack s = Stack(100);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    while(!s.isEmpty()){
        cout << s.stackTop() << endl;
        s.pop();
    }
    s.stackTop();
    return 0;
}