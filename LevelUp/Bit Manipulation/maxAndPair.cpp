#include<bits/stdc++.h>
using namespace std;

int checkBit(int res,vector<int> nums){
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if((res & nums[i]) == res){
            cnt++;
        }
    }
    return cnt;
}

int checkMax(vector<int> nums){
    int res = 0;
    for(int i = 31; i >= 0; i--){
        if(checkBit((res | (1 << i)),nums) >= 2){
            res = res | (1<<i);
        }
    }
    return res;
}

int main(){
    vector<int> v{4,8,12,16};
    cout << checkMax(v) << endl;
    return 0;
}