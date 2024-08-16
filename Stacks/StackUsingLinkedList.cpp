#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
    public:
        Node *top;
        Stack(){
            top = NULL;
        }

        void push(int x);
        int pop();
        void display();
        int topElement();
};

void Stack::push(int x){
    Node *t = new Node;
    if(t == NULL){
        cout << "Stack is full" << endl;
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int Stack::pop(){
    if(top == NULL){
        cout << "Stack underflow" << endl;
        return -1;
    }
    int x =top->data;
    top = top->next;
    return x;  
}

void Stack::display(){
    if(top!=NULL){
        Node *t = new Node;
        t=top;
        while(t){
            cout << t->data << " ";
            t=t->next;
        }
        cout << endl;
    }
}

int Stack::topElement(){
    if(top == NULL){
        cout << "Stack underflow" << endl;
        return -1;
    }
    return top->data;
}

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.display();
    cout << "popped element is: " << st.pop() << endl;
    st.display();
    cout << "Stack top element is: " << st.topElement() << endl;
    return 0;
}
