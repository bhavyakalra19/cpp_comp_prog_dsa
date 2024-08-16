#include<bits/stdc++.h>
using namespace std;

bool sortLexico(string s1, string s2){
    string xy = s1 + s2;
    string yx = s2 + s1;
    return xy > yx ? 1 : 0;
}

int main(){
    vector<string> v{"10","20","30","3"};
    sort(v.begin(),v.end(),sortLexico);
    for(string s : v){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}