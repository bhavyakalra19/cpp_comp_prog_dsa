#include<bits/stdc++.h>
using namespace std;

int ladder(int x, int k){
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= x; i++){
        if(i-k >= 1){
            dp[i] = 2*dp[i-1] - dp[i-k-1];
        }else{
            dp[i] = 2*dp[i-1];
        }
    }
    return dp[x];
}

int main(){
    cout << ladder(4,3) << endl;
    return 0;
}