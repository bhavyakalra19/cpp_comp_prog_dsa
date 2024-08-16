#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getAns(vector<int> &coins, int amount, vector<int> &dp) {
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mnAns = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(coins[i] > amount){
                continue;
            }
            int ans = getAns(coins,amount - coins[i],dp);
            if(ans != INT_MAX){
                mnAns = min(ans + 1,mnAns);
            }
        }
        return dp[amount] = mnAns;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = getAns(coins,amount,dp);
        return ans == INT_MAX ? -1 : ans;
    }

};

int main(){
    vector<int> v{1,2,3,4};
    Solution s;
    cout << s.coinChange(v,16) << endl;
    return 0;
}