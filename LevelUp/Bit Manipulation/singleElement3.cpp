#include<bits/stdc++.h>
using namespace std;

vector<int> singleElement(vector<int> nums){
    int xy = 0;
    for(int i = 0; i < nums.size(); i++){
        xy ^= nums[i];
    }

    int mask = 1;
    while((xy & mask) == 0){
        mask = mask << 1;
    }
    int x = 0;
    for(int i = 0; i < nums.size(); i++){
        if((mask & nums[i])==0){
            x ^= nums[i];
        }
    }
    return {x,xy^x};
}

int main(){
    vector<int> v{2,2,2,2,3,5};
    v = singleElement(v);
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}