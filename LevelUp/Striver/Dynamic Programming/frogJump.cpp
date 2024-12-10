// [10, 20, 30, 10] Reach last index with min cost of absoute diff between jumps

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int getAns(vector<int> &frogs, int idx, vector<int> &dp){
            if(idx < 1){
                return 0;
            }
            int a = abs(frogs[idx] - frogs[idx-1]) + getAns(frogs, idx-1,dp);
            int b = INT_MAX;
            if(idx - 2 >= 0){
                b = abs(frogs[idx] - frogs[idx-2]) + getAns(frogs, idx-2,dp);
            }
            return dp[idx] = min(a,b);
        }

        int frogJump(vector<int> frogs){
            int n = frogs.size();
            // return getAns(frogs,n-1,dp);
            int prev1 = 0;
            int prev2 = 0;
            int ss = INT_MAX;
            int curr;
            for(int i = 1; i < n; i++){
                int fs = abs(frogs[i] - frogs[i-1]) + prev1;
                
                if(i > 1){
                    ss = abs(frogs[i] - frogs[i-2]) + prev2;
                }
                curr = min(fs, ss);
                prev2 = prev1;
                prev1 = curr;
            }
            return curr;
        }
};

int main(){
    vector<int> frogs{30, 10,60,10,60,50};
    Solution s;
    cout << s.frogJump(frogs) << endl;
    return 0;
}