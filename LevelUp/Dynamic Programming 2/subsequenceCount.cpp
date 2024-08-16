#include<bits/stdc++.h>
using namespace std;

int subsequenceCount(string s1, string s2, int m, int n, vector<vector<int>> &dp){
    if(m == -1 && n == -1){
        return 1;
    }
    if(n == -1){
        return 1;
    }

    if(m == -1){
        return 0;
    }

    if(dp[m][n] != 0){
        return dp[m][n];
    }

    if(s1[m] == s2[n]){
        return dp[m][n] = subsequenceCount(s1,s2,m-1,n-1,dp) + subsequenceCount(s1,s2,m-1,n,dp);
    }
    return dp[m][n] = subsequenceCount(s1,s2,m-1,n,dp);
}

int main(){
    string s1 = "AABCDEC";
    string s2 = "ABC";
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    cout << subsequenceCount(s1,s2,m-1,n-1,dp) << endl;
    return 0;
}