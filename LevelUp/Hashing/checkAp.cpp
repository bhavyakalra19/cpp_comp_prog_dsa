#include<bits/stdc++.h>
using namespace std;

bool checkAp(vector<int> v){
    int n = v.size();
    int count = 0;
    unordered_map<int,int> mp;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i = 0; i < n; i++){
        mp[v[i]]++;
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    int diff = (mx - mn)/(n - 1);
    while(mp.find(mx) != mp.end()){
        count++;
        mx -= diff;
    }
    if(count == n){
        return true;
    }
    return false;
}

int main(){
    vector<int> v{0,12,4,8};
    if(checkAp(v) == true){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;  
}