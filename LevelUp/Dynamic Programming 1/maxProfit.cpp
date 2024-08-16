#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mxProfit = 0;
        int mxvalue = prices[n - 1];
        for(int i = n - 2; i >= 0; i--){
            mxProfit = max(mxvalue - prices[i],mxProfit);
            if(prices[i] > mxvalue){
                mxvalue = prices[i];
            }
        }
        return mxProfit;
    }
};

int main(){
    vector<int> v{7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(v) << endl;
    return 0;
}