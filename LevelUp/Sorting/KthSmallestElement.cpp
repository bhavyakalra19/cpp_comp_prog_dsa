#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int s, int e){
    int i = s - 1;
    int j = s;
    int pivot = nums[e];
    for(;j < e; j++){
        if(nums[j] < pivot){
            swap(nums[++i],nums[j]);
        }
    }
    swap(nums[e],nums[++i]);
    return i;
}

int quickSort(vector<int> &nums,int s, int e, int k){
    if(s > e){
        return -1;
    }
    int pivot = partition(nums,s,e);
    if(pivot == k){
        return nums[pivot];
    }else if(pivot < k){
        return quickSort(nums, pivot + 1, e, k);
    }else{
        return quickSort(nums, s, pivot - 1, k);
    }
}

int main(){
    vector<int> v{10,5,2,0,7,6,4};
    cout << quickSort(v,0,v.size()-1,10) << endl;
    return 0;
}