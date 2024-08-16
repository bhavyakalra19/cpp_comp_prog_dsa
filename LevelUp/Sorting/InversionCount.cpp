#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int s, int mid, int e){
    int i = s;
    int j = mid + 1;
    int count = 0;
    vector<int> v;
    while(s <= mid && j <= e){
        if(nums[s] <= nums[j]){
            v.push_back(nums[s++]);
        }else{
            //mid - s + 1 will count the cases if lower element of left array is bigger than element of right array then bigger elements of array left will not be able to compare with that element . so it will be included in this case.
            count += mid - s + 1;
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
    return count;
}

int mergeSort(vector<int> &nums, int s, int e){
    if(s >= e){
        return 0;
    }
    int mid = (s + e)/2;
    int x = mergeSort(nums,s,mid);
    int y = mergeSort(nums,mid+1,e);
    return x + y + merge(nums,s,mid,e);
}

int main(){
    vector<int> v{0,5,2,3,1,4};
    cout << mergeSort(v,0,v.size()-1) << endl;
    return 0;
}