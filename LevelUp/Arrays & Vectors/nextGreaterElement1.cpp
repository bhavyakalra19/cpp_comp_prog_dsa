#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && v[i] > st.top()){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(v[i]);
    }
    return ans;
}

int main(){
    vector<int> ans = nextGreater({1,2,1});
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}