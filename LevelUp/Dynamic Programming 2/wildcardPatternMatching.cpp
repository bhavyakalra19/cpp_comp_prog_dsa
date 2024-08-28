#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
            bool getAns(string pattern, string str, int i, int j, vector<vector<int>> &dp){
            if(i == pattern.size() && j == str.size()){
                return true;
            }
            if(j == str.size()){
                while(i < pattern.size() && pattern[i] == '*'){
                    i++;
                }
                if(i == pattern.size() && j == str.size()){
                    return true;
                }
                return false;
            }
            if(i == pattern.size()){
                return false;
            }
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            if(pattern[i] == '?' || (pattern[i] == str[j])){
                return dp[i][j] = getAns(pattern, str, i+1, j+1,dp);
            }else if(pattern[i] == '*'){
                return dp[i][j] = getAns(pattern,str,i+1,j+1,dp) | getAns(pattern,str,i,j+1,dp) | getAns(pattern,str,i+1,j,dp);
            }
            return dp[i][j] = false;
        }
        int wildCard(string pattern, string str) {
            int i = pattern.size();
            int j = str.size();
            vector<vector<int>> dp(i,vector<int>(j,-1));
            return getAns(pattern,str,0,0,dp);
        }
};

int main(){
    Solution s;
    cout << s.wildCard("ba*a?","baaabab") << endl;
    return 0;
}