#include<bits/stdc++.h>
using namespace std;

void subSequence(string s1,vector<string> &v, string output){
    if(s1[0] == '\0'){
        v.push_back(output);
        return;
    }
    subSequence(s1.substr(1),v,output+s1[0]);
    subSequence(s1.substr(1),v,output);
}

bool sortlexico(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length() ? 1 : 0;  
}

int main(){    
    vector<string> v; 
    subSequence("abc",v,"");
    sort(v.begin(),v.end(),sortlexico);
    for(string s : v){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}