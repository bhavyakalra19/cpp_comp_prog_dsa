#include<bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int> arr,int k){
    //complete this method
    unordered_map<int,int> mp;
    int cs = 0;
    int res = 0;
    for(int i = 0; i < arr.size(); i++){
        cs += arr[i];
        if(cs == k){
            res++;
        }
        
        if(mp.find(cs-k) != mp.end()){
            res += mp[cs-k];
        }
        mp[cs]++;
    }
    return res;
}

int main(){
    cout << cntSubarrays({1,2,3,4,5},10) << endl;
    return 0;
}