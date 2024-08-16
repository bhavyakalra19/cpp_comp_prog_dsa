#include<bits/stdc++.h>
using namespace std;

int fibonacciSeries(int x){
    int dp[x+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < x + 1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[x];
}

int main(){
    cout << fibonacciSeries(6) << endl;
    return 0;
}