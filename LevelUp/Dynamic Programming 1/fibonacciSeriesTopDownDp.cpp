#include<bits/stdc++.h>
using namespace std;

int fibonaciSeries(int x, vector<int> &dp){
    if(x == 0 || x == 1){
        return x;
    }
    if(dp[x] != 0){
        return dp[x];
    }
    return dp[x] = fibonaciSeries(x-1,dp) + fibonaciSeries(x-2,dp);
}

int main(){
    vector<int> v(6+1,0);
    fibonaciSeries(6,v);
    cout << v[6] << endl;
    return 0;
}