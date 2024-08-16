#include<bits/stdc++.h>
using namespace std;

int rotatedSearch(vector<int> nums,int key){
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    while(s <= e){
        int mid  = (s + e)/2;
        if(nums[mid] == key){
            return mid;
        }
        if(nums[s] <= nums[mid]){
            if(key >= nums[s] && key < nums[mid]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }else{
            if(key <= nums[e] && key > nums[mid]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> v{7,8,9,1,2,3,4,5,6};
    cout << rotatedSearch(v,4) << endl;
    return 0;
}