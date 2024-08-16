#include<bits/stdc++.h>
using namespace std;

char KthNonRepeatingChar(string str, int k){
    unordered_map<char,int> mp;
    for(int i = 0; i < str.length(); i++){
        mp[str[i]]++;
    }
    int nonRe = 0;
    for(int i = 0; i < str.length(); i++){
        if(mp[str[i]] == 1){
            nonRe++;
            if(nonRe == k){
                return str[i];
            }
        }
    }
    return '\0';
}

int main(){
    string s = "geeksforgeeks";
    cout << KthNonRepeatingChar(s,3) << endl;
    cout << KthNonRepeatingChar(s,4) << endl;
}