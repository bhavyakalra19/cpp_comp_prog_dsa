#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int getAns(int i, int n, vector<vector<vector<int>>> &dp, int clt, int at){
        if(i == n){
            return 1;
        }
        if(dp[i][clt][at] != -1){
            return dp[i][clt][at];
        }
        long long ans = 0;
        ans += getAns(i+1,n,dp,0,at)%mod;
        if(clt < 2){
            ans += getAns(i+1,n,dp,clt+1,at)%mod;
        }
        if(at < 1){
            ans += getAns(i+1,n,dp,0,1)%mod;
        }
        return dp[i][clt][at] = ans%mod;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return getAns(0,n,dp,0,0);
    }
};

int main(){
    Solution s;
    cout << s.checkRecord(4) << endl;
    return 0;
}