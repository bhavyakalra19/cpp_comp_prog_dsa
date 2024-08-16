#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + LongestCommonSubsequence(s1,s2,i+1,j+1,dp); 
    }
    int op1 = LongestCommonSubsequence(s1,s2,i+1,j,dp);
    int op2 = LongestCommonSubsequence(s1,s2,i,j+1,dp);
    return dp[i][j] = max(op1,op2);
}

int main(){
    string s1 = "ABCD";
    string s2 = "ABCEGD";
    vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),0));
    cout << LongestCommonSubsequence(s1,s1,0,0,dp) << endl;
    return 0;
}