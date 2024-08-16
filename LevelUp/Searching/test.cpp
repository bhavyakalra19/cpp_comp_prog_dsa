#include<bits/stdc++.h>
using namespace std;

int getOutput(int a, int b){
    int ans = 0;
    int x = a;
    while(b > 1){
        ans = 0;
        for(int i = 0; i < x; i++){
            ans += a;
        }
        cout << ans << endl;
        a = ans;
        b = b - 1;
    }
    return ans;
}

int main(){
    int a = 0;
    int b = 4;
    cout << getOutput(a,b) << endl;
    return 0;
}