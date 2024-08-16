#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int s, int mid, int e){
    int i = s;
    int j = mid + 1;
    vector<int> v;
    while(s <= mid && j <= e){
        if(nums[s] < nums[j]){
            v.push_back(nums[s++]);
        }else{
            v.push_back(nums[j++]);
        }
    }
    while(s <= mid){
        v.push_back(nums[s++]);
    }

    while(j <= e){
        v.push_back(nums[j++]);
    }

    for(int j = 0; j < v.size(); j++){
        nums[j+i] = v[j];
    }
}

void mergeSort(vector<int> &nums, int s, int e){
    if(s >= e){
        return;
    }
    int mid = (s + e)/2;
    mergeSort(nums,s,mid);
    mergeSort(nums,mid+1,e);
    merge(nums,s,mid,e);
}

int main(){
    vector<int> v{0,5,2,3,1,4,6,7};
    mergeSort(v,0,v.size()-1);
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}