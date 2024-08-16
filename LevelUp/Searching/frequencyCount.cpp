#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> nums, int key){
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(nums[mid] == key){
            ans = mid;
            s = mid + 1;
        }else if(nums[mid] > key){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}

int lowerBound(vector<int> nums, int key){
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(nums[mid] == key){
            ans = mid;
            e = mid - 1;
        }else if(nums[mid] > key){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return ans;
}

int frequencyCount(vector<int> nums, int key){
    return upperBound(nums,key) - lowerBound(nums,key) + 1;
}

int main(){
    vector<int> v{1,1,1,2,3,3,4,4,4,4,5,6,7,8,9};
    cout << frequencyCount(v,4) << endl;
    return 0;
}