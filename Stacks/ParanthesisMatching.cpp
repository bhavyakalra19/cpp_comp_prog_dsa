#include<bits/stdc++.h>
using namespace std;

struct StackNode{
    int size;
    int top;
    char *arr;
};

void push(StackNode *temp, char c){
    temp->arr[++temp->top] = c;
}

void display(StackNode *temp){
    if(temp->top == -1){
        cout << "Stack is empty" << endl;
    }
    for(int i = temp->top; i >= 0 ; i--){
        cout << temp->arr[i] << " ";
    }
    cout << endl;
}

void pop(StackNode *temp){
    temp->top--;
}

void create(StackNode *p,int size){
    p->size = size;
    p->arr = new char[size];
    p->top = -1;
}

bool checkParanthesis(StackNode *temp, string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='('){
            push(temp,s[i]);
        }else if(s[i] == ')'){
            if(temp->top == -1){
                return false;
            }
            pop(temp);
        }
    }

    if(temp->top != -1){
        return false;
    }
    return true;
}

int main(){
    StackNode *st = new StackNode;
    string s = "((a+b)*(c+d))";
    create(st,6);
    if(checkParanthesis(st,s)){
        cout << "Paranthesis complete" << endl;
    }else{
        cout << "Paranthesis uncomplete" << endl;
    }
    return 0;
}