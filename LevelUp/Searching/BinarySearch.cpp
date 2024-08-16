#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int key){
    int n = v.size();
    int s = 0;
    int  e = n - 1;
    while(s<=e){
        int mid = (s + e)/2;
        if(v[mid] == key){
            return mid;
        }else if(v[mid] < key){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    cout << binarySearch(v,6) << endl;
    return 0;
}