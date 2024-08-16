#include<bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> arr, int i){
    if(i==0){
        return arr[0] > arr[1];
    }
    if(i==arr.size()-1){
        return arr[i-1] > arr[i];
    }
    return (arr[i-1] > arr[i]) || (arr[i] > arr[i+1]);
}

pair<int,int> subArraySort(vector<int> arr){
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(outOfOrder(arr,i)){
            minValue = min(minValue,arr[i]);
            maxValue = max(maxValue,arr[i]);
        }
    }
    int j = 0;
    int k = n-1;
    for(int i=0; i<n; i++){
        if(arr[i] < minValue){
            j++;
        }
        if(arr[n-i-1] > maxValue){
            k--;
        }
    }
    return {j,k};
}

int main(){
    vector<int> v{1,2,3,4,5,8,7,6,10,9,11,12};
    // vector<int> v{1,2,3,4,5,8,6,7,9,10,11,12};
    pair<int,int> p;
    p = subArraySort(v);
    cout << p.first << " " << p.second << endl;
    return 0;
}