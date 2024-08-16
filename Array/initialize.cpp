#include<bits/stdc++.h>
using namespace std;

struct Array{
    int A[20];
    int size;
};

void display(int *arr,int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    struct Array arr = {{1,2,3,4,5,6},6};
    display(arr.A, arr.size);
    return 0;
}
