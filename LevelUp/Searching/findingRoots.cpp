#include<bits/stdc++.h>
using namespace std;

float findingRoots(int num,int p){
    int s = 0;
    int e = num;
    float ans = 0;
    while(s <= e){
        int mid = (s+e)/2;
        int sq = mid*mid;
        if(sq == num){
            return mid;
        }else if(sq < num){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    float a  = 0.1;
    for(int i = 1; i <= p; i++){
        while(ans*ans < num){
            ans += a;
        }
        ans -= a;
        a *= 0.1;
    }
    return ans;
}

int main(){
    cout << findingRoots(10,3) << endl;
    return 0;
}
