#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> nums){
    int num = 0;
    for(int i = 0; i < nums.size(); i++){
        num ^= nums[i];
    }
    return num;
}

int main(){
    vector<int> v{2,2,3};
    cout << singleElement(v) << endl;
    return 0;
}