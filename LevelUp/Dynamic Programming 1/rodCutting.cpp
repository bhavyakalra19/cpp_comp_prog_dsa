#include<bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> prices, int len, vector<int> &dp){
    if(len == 0){
        return 0;
    }
    if(dp[len] != 0){
        return dp[len];
    }
    int ans = INT_MIN;
    for(int i = 0; i < len; i++){
        int cl = i + 1;
        int subAns = prices[i] + rodCutting(prices, len - cl, dp);
        ans = max(ans,subAns);
    }
    return dp[len] = ans;
}

int main(){
    vector<int> v{1,5,8,9,10,17,17,20};
    vector<int> dp(9,0);
    cout << rodCutting(v,8,dp) << endl;
    return 0;
}