#include<bits/stdc++.h>
using namespace std;

int mountain(vector<int> nums){
    int largest = 0;
    for(int i=1; i<nums.size()-1;){
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
            int cnt = 1;
            int j = i;
            while(j>=1 && nums[j] > nums[j-1]){
                cnt++;
                j--;
            }
            while(i<=nums.size()-2 && nums[i] > nums[i+1]){
                cnt++;
                i++;
            }
            largest = max(cnt,largest);
        }else{
            i++;
        }
    }
    return largest;
}

int main(){
    vector<int> v{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout << mountain(v) << endl;
    return 0;
}