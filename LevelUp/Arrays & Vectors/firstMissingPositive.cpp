#include<bits/stdc++.h>
using namespace std;

int missingPositive(vector<int> nums){
    int n = nums.size();
    
    //checking number less than and equal to zero
    for(int i = 0; i < n; i++){
        if(nums[i] <= 0){
            nums[i] = n+1;
        }
    }

    //create index value to negative
    for(int i = 0; i < n; i++){
        int index = abs(nums[i]) - 1;
        if(index < n){
            nums[index] = abs(nums[index])*-1;
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i]>0){
            return i+1;
        }
    }
    return n+1;
}

int main(){
    vector<int> v{-10,0,1,2,4,5,6,3,8};
    cout << missingPositive(v) << endl;
    return 0;
}