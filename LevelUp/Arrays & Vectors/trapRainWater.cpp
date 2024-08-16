#include<bits/stdc++.h>
using namespace std;

int trapRainWater(vector<int> height){
    int n = height.size();
    int leftMax = 0, rightMax = 0;
    int *left = new int[n];
    int *right = new int[n];
    for(int i =0; i<n; i++){
        leftMax = max(leftMax,height[i]);
        rightMax = max(rightMax,height[n-i-1]);
        left[i] = leftMax;
        right[n-i-1] = rightMax;
    }
    int trappedWater = 0;
    for(int i=0; i<n; i++){
        trappedWater += min(left[i],right[i]) - height[i];
    }
    return trappedWater;
}

int main(){
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water in above vector is: " << trapRainWater(height) << endl;
    return 0;
}