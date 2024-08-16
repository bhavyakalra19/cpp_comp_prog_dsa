#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        int mx;
        int mxValue = 0;
        for(char c : s){
            mx = 0;
            int cV = c - 'a';
            int i = max(cV - k,0);
            int j = min(cV + k,25);
            for(;i <= j; i++){
                mx = max(mx,dp[i]);
            }
            dp[cV] = mx + 1;
            if(mx + 1 > mxValue){
                mxValue = mx + 1;
            }
        }
        return mxValue;
    }
};

int main(){
    Solution s;
    cout << s.longestIdealString("dyyonfvzsretqxucmavxegvlnnjubqnwrhwikmnnrpzdovjxqdsatwzpdjdsneyqvtvorlwbkb",7) << endl;
    return 0;
}