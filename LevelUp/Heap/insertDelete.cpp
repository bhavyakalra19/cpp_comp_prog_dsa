#include<bits/stdc++.h>
using namespace std;

void insertHeap(vector<int> &nums, int key){
    if(nums.size() == 0){
        nums.push_back(0);
    }
    int n = nums.size();
    nums.push_back(key);
    int i = n;
    while(i > 1 && key > nums[i/2]){
        nums[i] = nums[i/2];
        i = i/2;
    }
    nums[i] = key;
}

int deleteHeap(vector<int> &nums){
    int n = nums.size() - 1;
    if(n == 0){
        return -1;
    }
    int i = 1;
    int temp = nums[i];
    nums[i] = nums[n];
    int j = i*2;
    while(j < n){
        if(j < n-1 && nums[j] < nums[j+1]){
            j = j+1;
        }
        if(nums[i] < nums[j]){
            swap(nums[i],nums[j]);
            i = j;
            j = i*2;
        }else{
            break;
        }
    }
    nums.pop_back();
    return temp;
}

int main(){
    vector<int> v{3,5,2,4,1};
    vector<int> ans;
    for(int i = 0; i < v.size(); i++){
        insertHeap(ans,v[i]);
    }
    while(ans.size() != 1){
        cout << deleteHeap(ans) << " ";
    }
    cout << endl;
    return 0;
}