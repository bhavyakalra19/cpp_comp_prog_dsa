#include<bits/stdc++.h>
using namespace std;

int largestBand(vector<int> nums){
    unordered_set<int> s;
    int largest = 0;
    for(int i=0; i<nums.size();i++){
        s.insert(nums[i]);
    }
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i]-1)==s.end()){
            int cnt = 1;
            int j = nums[i]+1;
            while(s.find(j)!=s.end()){
                cnt++;
                j++;
            }
            largest = max(largest,cnt);
        }
    }
    return largest;
}

int main(){
    vector<int> v{1,9,3,0,18,5,2,4,10,7,12,6};
    cout << largestBand(v) << endl;
    return 0;
}