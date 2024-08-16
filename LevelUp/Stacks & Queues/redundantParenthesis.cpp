#include<bits/stdc++.h>
using namespace std;

bool redundantParanthesis(string s){
    stack<char> st;
    bool op = true;
    for(auto ch : s){
        if(ch != ')'){
            st.push(ch);
            op = false;
        }else{
            while(!st.empty() && st.top() != '('){
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                    op = true;
                }
                st.pop();
            }
            if(st.top() == '(' && op == false){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return true;
}

int main(){
    string s = "(a + b + c)";
    if(redundantParanthesis(s)){
        cout << "valid" << endl;
    }else{
        cout << "Invalid" << endl;
    }
    return 0;
}