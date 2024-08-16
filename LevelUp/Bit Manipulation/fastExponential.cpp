#include<bits/stdc++.h>
using namespace std;

int fastExponential(int n, int p){
    int ans = 1;
    while(p>0){
        int rem = p&1;
        if(rem){
            ans *= n;
        }
        p = p>>1;
        n = n*n;
    }
    return ans;
}

int main(){
    cout << fastExponential(2,4) << endl;
    return 0;
}