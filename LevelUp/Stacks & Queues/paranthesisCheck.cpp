#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string s){
    stack<char> st;
    for(auto ch : s){
        switch(ch){
            case '{':
            case '[':
            case '(':
                st.push(ch);
                break;
            case ']':
                if(!st.empty() && st.top() != '['){
                    return false;
                }else{
                    st.pop();
                }
                break;
            case '}':
                if(!st.empty() && st.top() != '{'){
                    return false;
                }else{
                    st.pop();
                }
                break;
            case ')':
                if(!st.empty() && st.top() != '('){
                    return false;
                }else{
                    st.pop();
                }
                break;
            default:
                continue;
        }
    }
    return true;
}

int main(){
    string s = "{a+b}";
    if(validParenthesis(s)){
        cout << "Valid" << endl;
    }else{
        cout << "Invalid" << endl;
    }
    return 0;
}