#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getAns(vector<int> &coins, int amount, int index) {
        if(amount == 0){
            return 0;
        }
        int mnAns = INT_MAX;
        for(int i = index; i < coins.size(); i++){
            if(coins[i] > amount){
                continue;
            }
            int ans = getAns(coins,amount - coins[i],i);
            if(ans != -1){
                mnAns = min(ans + 1,mnAns);
            }
        }
        return mnAns == INT_MAX ? -1 : mnAns;
    }

    int coinChange(vector<int>& coins, int amount) {
        return getAns(coins,amount,0);
    }

};

int main(){
    vector<int> coins{186,419,83,408};
    Solution s;
    cout << s.coinChange(coins,6249) << endl;
    return 0;
}