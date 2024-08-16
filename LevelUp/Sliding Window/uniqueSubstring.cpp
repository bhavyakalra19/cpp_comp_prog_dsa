#include<bits/stdc++.h>
using namespace std;

string uniqueSubstring(string s){
    int i = 0;
    int j = 0;
    int start_wind = -1;
    int wind_size = 0;
    int max_wind = 0;
    unordered_map<char,int> mp;
    while(j < s.length()){
        if(mp.count(s[j]) && mp[s[j]] >= i){
            i = mp[s[j]] + 1;
            wind_size = j - i;
        }
        mp[s[j]] = j;
        j++;
        wind_size++;
        if(wind_size > max_wind){
            start_wind = i;
            max_wind = wind_size;
        }
    }
    return s.substr(start_wind, max_wind);
}

int main(){
    string s = "geeksforgeeks";
    cout << uniqueSubstring(s) << endl;
    return 0;
}