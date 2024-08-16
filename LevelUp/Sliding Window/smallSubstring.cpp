#include<bits/stdc++.h>
using namespace std;

string smallSubstring(string s1, string s2){
    unordered_map<char,int> mp1;
    unordered_map<char,int> mp2;
    int c = 0;
    int start = 0;
    int wind_size = 0;
    string s = s2;
    for(int  i = 0; i < s1.length(); i++){
        mp1[s1[i]]++;
    }
    for(int i = 0; i < s2.length(); i++){
        mp2[s2[i]]++;
        if(mp1[s2[i]] > 0 && mp2[s2[i]] <= mp1[s2[i]]){
            c++;
        }
        if(c == s1.length()){
            while(mp1[s2[start]] == 0 || (mp2[s2[start]] > mp1[s2[start]])){
                mp2[s2[i]]--;
                start++;
            }
            wind_size = i - start + 1;
            if(wind_size < s.length()){
                s = s2.substr(start,wind_size);
            }
        }
    }
    return s;
}

int main(){
    cout << smallSubstring("lol","hello") << endl;
    return 0;
}