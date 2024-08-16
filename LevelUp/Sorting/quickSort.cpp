#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int s, int e){
    int i = s - 1;
    int pivot = nums[e];
    for(int j = s; j < e; j++){
        if(nums[j] < pivot){
            swap(nums[++i],nums[j]);
        }
    }
    swap(nums[++i],nums[e]);
    return i;
}

void quickSort(vector<int> &nums, int s, int e){
    if(s >= e){
        return;
    }
    int p = partition(nums,s,e);
    quickSort(nums,s,p-1);
    quickSort(nums,p+1,e);
}

int main(){
    vector<int> v{5,2,1,4,6};
    quickSort(v,0,v.size()-1);
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}