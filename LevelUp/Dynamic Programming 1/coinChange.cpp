#include<bits/stdc++.h>
using namespace std;

int coinChange(int x, vector<int> coin, vector<int> &dp){
    if(x == 0){
        return 0;
    }
    int ans = INT_MAX;
    for(int i = 0; i < coin.size(); i++){
        if(x - coin[i] >= 0){
            int subAns = 0;
            if(dp[x - coin[i]] != -1){
                subAns = dp[x - coin[i]];
            }else{
                subAns = coinChange(x - coin[i], coin, dp);
            }
            if(subAns + 1 < ans){
                ans = subAns + 1;
            }
        }
    }
    return dp[x] = ans;
}

int main(){
    int ans = INT_MAX;
    vector<int> v{1,2,3};
    vector<int> dp(7,-1);
    dp[0] = 0;
    coinChange(6,v,dp);
    cout << dp[6] << endl;
    return 0;
}