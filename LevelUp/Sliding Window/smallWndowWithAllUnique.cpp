#include<bits/stdc++.h>
using namespace std;

string smallSubstring(string s){
    unordered_set<char> mp1;
    unordered_map<char,int> mp2;
    int c = 0;
    int start = 0;
    int wind_size = 0;
    int min_wind = INT_MAX;
    int start_point  = 0;
    for(int i = 0; i < s.length(); i++){
        mp1.insert(s[i]);
    }

    for(int i = 0; i < s.length(); i++){
        mp2[s[i]]++;

        if(mp2[s[i]] == 1){
            c++;
        }
        if(c == mp1.size()){
            while(mp2[s[start]] > 1){
                mp2[s[start]]--;
                start++;
            }
            wind_size = i - start + 1;
            if(wind_size < min_wind){
                min_wind = wind_size;
                start_point = start;
            }
        }
    }
    return s.substr(start_point,min_wind);
}

int main(){
    cout << smallSubstring("aabcbcdbcaaad") << endl;
    return 0;
}