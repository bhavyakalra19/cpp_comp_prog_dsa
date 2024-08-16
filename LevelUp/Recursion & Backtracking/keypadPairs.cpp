#include<bits/stdc++.h>
using namespace std;

vector<string> keypad{"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void keypadPairs(string s1, vector<string> &v, string output){
    if(s1.empty()){
        v.push_back(output);
        return;
    }
    for(int i = 0; i < keypad[s1[0] - '0'].length(); i++){
        keypadPairs(s1.substr(1),v,output + keypad[s1[0] - '0'][i]);
    }
}

int main(){
    vector<string> v;
    keypadPairs("23",v,"");
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}