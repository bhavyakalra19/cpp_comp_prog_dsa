#include<bits/stdc++.h>
using namespace std;

pair<int,int> minumumDifference(vector<int> arr1, vector<int> arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(),arr2.end());
    int i=0, j=0;
    int diff = INT_MAX;
    pair<int,int> result;
    while(i < arr1.size() && j < arr2.size()){
        if(abs(arr1[i] - arr2[j]) < diff){
            diff = abs(arr1[i] - arr2[j]);
            result = make_pair(arr1[i],arr2[j]);
        }

        if(arr1[i]>arr2[j]){
            j++;
        }else{
            i++;
        }
    }
    return result;
}

int main(){
    vector<int> v1{23, 5, 10, 17, 30};
    vector<int> v2{26, 134, 135, 14, 19};
    pair<int,int> res = minumumDifference(v1,v2);
    cout << res.first << " " << res.second << endl;
    return 0;
}