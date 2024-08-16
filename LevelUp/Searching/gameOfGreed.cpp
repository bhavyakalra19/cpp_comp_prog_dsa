#include<bits/stdc++.h>
using namespace std;

bool checkPartition(vector<int> nums, int n, int p, int k){
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        if(sum>=p){
            cnt++;
            sum = 0;
        }
        if(cnt==k){
            return true;
        }
    }
    return false;
}

int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    int n = arr.size();
    int sum = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int s = 1;
    int e = sum;
    while(s <= e){
        int mid = (s+e)/2;
        if(checkPartition(arr,n,mid,k)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> v{10,20,30,15};
    cout << getCoins(v,2) << endl;
    return 0;
}
