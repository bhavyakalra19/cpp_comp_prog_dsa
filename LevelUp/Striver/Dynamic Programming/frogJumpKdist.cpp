// This is a follow-up question to “Frog Jump” discussed in the 
// previous article. In the previous question, the frog was allowed to
//  jump either one or two steps at a time. In this question, the frog 
//  is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can
//   jump 1,2,3, or 4 steps at every index.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        // int getAns(vector<int> &frogs, int idx, int k, vector<int> &dp){
        //     if(idx == 0){
        //         return 0;
        //     }
        //     if(dp[idx] != -1){
        //         return dp[idx];
        //     }
        //     int minSteps = INT_MAX;
        //     for(int i = 1; i <= min(idx,k); i++){
        //         minSteps = min(minSteps, abs(frogs[idx] - frogs[idx-i]) + getAns(frogs,idx - i,k,dp));
        //     }
        //     return dp[idx] = minSteps;
        // }
        
        int frogJump(vector<int> &frogs, int k){
            int n = frogs.size();
            vector<int> dp(n,-1);
            dp[0] = 0;
            for(int i = 1; i < n; i++){
                int minSteps = INT_MAX;
                for(int j = 1; j <= min(k,i); j++){
                    minSteps = min(minSteps, abs(frogs[i] - frogs[i-j]) + dp[i-j]);
                }
                dp[i] = minSteps;
            }
            return dp[n-1];
            // return getAns(frogs,n-1,k,dp);
        }
};

int main(){
    vector<int> frog{10, 40, 30, 10};
    Solution s;
    cout << s.frogJump(frog,2) << endl;
    return 0;
}