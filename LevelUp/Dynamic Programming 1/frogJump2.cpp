#include<bits/stdc++.h>
using namespace std;

int frogJump2(int k, int idx, vector<int> height, vector<int> &dp, int n){
    if(idx == n - 1){
        return 0;
    }
    if(dp[idx] != 0){
        return dp[idx];
    }
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++){
        if(idx + i < n){
            int subAns = abs(height[idx] - height[idx + i]) + frogJump2(k,idx + i,height,dp,n);
            ans = min(ans,subAns);
        }
    }
    return dp[idx] = ans;
}

int main(){
    vector<int> v{40,10,20,70,80,10,20,70,80,60};
    vector<int> dp(10,0);
    cout << frogJump2(5,0,v,dp,10) << endl;
    return 0;
}