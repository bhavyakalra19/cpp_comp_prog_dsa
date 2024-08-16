#include<bits/stdc++.h>
using namespace std;

void reverse(string &s, int i,int j){
    while(i > j){
        swap(s[i++],s[j--]);
    }
}

string nextPermutation(string s){
    int n = s.length();
    int i = n-2;
    for(; i>=0; i--){
        if(s[i]<s[i+1]){
            break;
        }
    }
    if(i>=0){
        for(int j = n-1; j > i; j--){
            if(s[j]>s[i]){
                swap(s[j],s[i]);
            }
        }
    }
    reverse(s,i+1,n-1);
    return s;
}

int nextGreaterElement(int n) {
    string s = nextPermutation(to_string(n));
    long l = stol(s);
    return l > (long)INT_MAX ? -1 : l == long(n) ? -1 : l;
}

int main(){
    cout << nextGreaterElement(12345) << endl;
    return 0;
}