#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = 2*n - 1; i >= 0; i--){
        while(!st.empty() && v[i%n] >= st.top()){
            st.pop();
        }

        if(i < n){
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
        }
        st.push(v[i%n]);
    }
    return ans;
}

int main(){
    vector<int> v{1,2,1};
    v = nextGreaterElement(v);
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}