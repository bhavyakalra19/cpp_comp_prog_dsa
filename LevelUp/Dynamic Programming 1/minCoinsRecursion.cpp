#include<bits/stdc++.h>
using namespace std;

void coinChange(int x, int index, int pos, vector<int> coin, int &ans){
    if(x == 0){
        if(pos < ans){
            ans = pos;
        }
        return;
    }
    if(x < 0){
        return;
    }
    for(int i = index; i < coin.size(); i++){
        if(coin[i] > x){
            continue;
        }
        coinChange(x - coin[i], i, pos + 1, coin, ans);
    }
}

int main(){
    int ans = INT_MAX;
    vector<int> v{1,2,3};
    coinChange(6,0,0,v,ans);
    cout << ans << endl;
    return 0;
}