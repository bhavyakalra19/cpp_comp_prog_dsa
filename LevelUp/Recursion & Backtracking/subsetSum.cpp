#include<bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> v, int n, int output){
    if(output == 0){
        return 1;
    }
    if(output < 0 || n == v.size()){
        return 0;
    }
    return subsetSum(v,n+1,output - v[n]) + subsetSum(v,n+1,output);
}

int main(){
    vector<int> v{10,12,14,6,4,2};
    cout << subsetSum(v,0,16) << endl;
    return 0;
}