#include<bits/stdc++.h>
using namespace std;

int knapsackMax(vector<int> nodes, vector<int> prices, int n, int w, vector<vector<int>> &dp){
    if(n == -1 || w == 0){
        return 0;
    }

    if(dp[n][w] != 0){
        return dp[n][w];
    }
    int op1 = 0;
    if(nodes[n] <= w){
        op1 = prices[n] + knapsackMax(nodes,prices,n-1,w-nodes[n],dp);
    }
    int op2 = knapsackMax(nodes,prices,n-1,w,dp);
    return dp[n][w] = max(op1,op2);
}

int main(){
    vector<int> nodes{2,7,3,4};
    vector<int> prices{5,20,20,10};
    int n = nodes.size();
    vector<vector<int>> dp(n,vector<int>(11,0));
    cout << knapsackMax(nodes,prices,n-1,11,dp) << endl;
    return 0;
}