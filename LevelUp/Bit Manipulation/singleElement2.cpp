#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> v){
    int ans = 0;
    for(int i = 0; i < 32; i++){
        int sum = 0;
        for(int j = 0; j < v.size(); j++){
            sum += (v[j] >> i) & 1;
        }
        ans |= (sum % 3)<<i;
    }
    return ans;
}

int main(){
    vector<int> v{2,2,2,3,4,4,4};
    cout << singleElement(v) << endl;
    return 0;
}