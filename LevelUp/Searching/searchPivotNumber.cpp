#include<bits/stdc++.h>
using namespace std;

int checkNumber(int num){
    if(num == 1){
        return num;
    }
    vector<int> v;
    int sum = 0;
    int low;
    for(int i = 1; i <= num; i++){
        v.push_back(i);
    }
    int n = v.size();
    for(int i = 0; i < n; i++){
        sum += v[i];
        v[i] = sum;
    }
    int high = v[n-1];
    int s = 1;
    num = num - 2;
    while(s<num){
        int mid = (s+num)/2;
        low = v[mid-1];
        int diff = high - v[mid];
        if(low == diff){
            return mid + 1;
        }else if(diff > low){
            s = mid + 1;
        }else{
            num = mid - 1;
        }
    }
    return -1;
}

int main(){
    cout << checkNumber(8) << endl;
}