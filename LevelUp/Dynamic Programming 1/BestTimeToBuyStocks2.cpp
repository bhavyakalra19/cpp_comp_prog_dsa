#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1){
            return 0;
        }
        int mx = prices[n - 1];
        int sum = 0;
        for(int i = n - 2; i >= 0; i--){
            if(prices[i] >= mx){
                mx = prices[i];
            }else{
                sum += mx - prices[i];
                mx = prices[i];
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> v{7,1,5,3,6,4};
    cout << s.maxProfit(v) << endl;
    return 0;
}