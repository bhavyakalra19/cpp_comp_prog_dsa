#include<bits/stdc++.h>
using namespace std;

int getAns(int num, vector<int> &dp){
    if(num <= 1){
        return num;
    }
    if(dp[num] != -1){
        dp[num];
    }
    return dp[num] = getAns(num - 1, dp) + getAns(num - 2, dp);
}

int getFib(int num){
    vector<int> dp(num + 1, -1);
    // return getAns(num, dp);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= num; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}

int main(){
    cout << getFib(5) << endl;
    return 0;
}