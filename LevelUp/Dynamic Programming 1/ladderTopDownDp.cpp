#include<bits/stdc++.h>
using namespace std;

int ladder(int x, int k, vector<int> &dp){
    if(x == 0){
        return 1;
    }
    if(x < 0){
        return 0;
    }
    if(dp[x] != 0){
        return dp[x];
    }
    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans += ladder(x-i,k,dp);
    }
    return dp[x] = ans;
}

int main(){
    vector<int> v(5,0);
    cout << ladder(4,3,v) << endl;
    return 0;
}
