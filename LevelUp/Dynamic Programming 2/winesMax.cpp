#include<bits/stdc++.h>
using namespace std;

int winesMax(vector<int> prices, int i, int j, vector<vector<int>> &dp, int y){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    int op1 = prices[i] * y + winesMax(prices,i+1,j,dp,y+1);
    int op2 = prices[j] * y + winesMax(prices,i,j-1,dp,y+1);
    return dp[i][j] = max(op1,op2);
}

int main(){
    vector<int> prices{2,3,5,1,4};
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    cout << winesMax(prices,0,n-1,dp,1) << endl;
    return 0;
}