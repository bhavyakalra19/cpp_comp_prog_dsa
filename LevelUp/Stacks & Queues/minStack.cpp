#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        stack<int> mainStack;
        stack<int> minStack;

        void push(int val){
            mainStack.push(val);
            if(minStack.empty() || minStack.top() >= val){
                minStack.push(val);
            }
        }

        void pop(){
            if(mainStack.top() == minStack.top()){
                minStack.pop();
            }
            mainStack.pop();
        }

        int top(){
            return mainStack.top();
        }

        int getMin(){
            return minStack.top();
        }
};


int main(){
    Solution s;
    s.push(2);
    s.push(4);
    s.push(4);
    s.push(2);
    s.push(1);
    s.push(1);
    while(!s.minStack.empty()){
        cout << s.getMin() << endl;
        s.pop();
    }
    return 0;
}