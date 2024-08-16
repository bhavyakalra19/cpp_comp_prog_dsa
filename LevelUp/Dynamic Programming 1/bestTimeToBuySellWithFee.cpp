#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int rec(vector<int> &prices, int fee, int i, vector<vector<int>> &dp, int b){
        if(i>=n) return 0;
        if(dp[b][i]!=-1) return dp[b][i];
        if(b){
            return dp[b][i] = max(prices[i]-fee+rec(prices, fee, i+1, dp, 0) , rec(prices, fee,i+1, dp, 1));
        }
        else{
            return dp[b][i] = max(-prices[i]+rec(prices, fee, i+1, dp, 1) , rec(prices, fee,i+1, dp, 0));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n+1, -1));
        return rec(prices, fee, 0, dp, 0);
    }
};

int main(){
    Solution s;
    vector<int> v{1,3,2,8,4,9};
    cout << s.maxProfit(v,2) << endl;
    return 0;
}