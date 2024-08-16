#include<bits/stdc++.h>
using namespace std;

int convertDecimalToBinary(int n){
    int ans = 0;
    int rem;
    int p = 1;
    while(n>0){
        rem = n % 2;
        ans += (rem*p);
        n /= 2;
        p *= 10;
    }
    return ans;
}

int main(){
    cout << convertDecimalToBinary(10) << endl;
    return 0;
}