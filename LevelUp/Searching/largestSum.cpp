#include<bits/stdc++.h>
using namespace std;

bool checkPartition(vector<int> arr, int n, int p, int k){
    int cnt = 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]>p){
            return false;
        }
        if(sum + arr[i] > p){
            cnt++;
            sum = arr[i];
            if(cnt > k){
                return false;
            }
        }else{
            sum += arr[i];
        }
    }
    return true;
}

int minPages(vector<int> arr, int k){
      //return the max coins that you can win!
    int n = arr.size();
    int e = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        e += arr[i];
    }
    int s = 1;
    while(s <= e){
        int mid = (s+e)/2;
        if(checkPartition(arr,n,mid,k)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> v{13,5,7,9};
    cout << minPages(v,2) << endl;
    return 0;
}