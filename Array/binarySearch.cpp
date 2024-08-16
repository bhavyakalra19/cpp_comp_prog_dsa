#include<bits/stdc++.h>
using namespace std;

struct Array{
    int A[20];
    int size;
    int length;
};

void display(int *arr,int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Binary search on array.
int binarySearch(struct Array *arr, int l, int h, int key){
    while(l<=h){
        int mid = (l+h)/2;
        if(key == arr->A[mid]){
            return mid;
        }else if(key < arr->A[mid]){
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return -1;
}


//Binary search on array using recursion
int binarySearhRecursion(struct Array *arr, int l, int h, int key){
    if(l<=h){
        int mid = (l+h)/2;
        if(key == arr->A[mid]){
            return mid;
        }else if(key < arr->A[mid]){
            return binarySearhRecursion(arr,l,mid-1,key);
        }else{
            return binarySearhRecursion(arr,mid+1,h,key);
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{1,2,3,4,5,6},10,6};
    display(arr.A, arr.length);
    int index = binarySearhRecursion(&arr,0,5,4);
    if(index != -1){
        cout << "Index is: " << index << endl;
    }else{
        cout << "Not found" << endl;
    }
    return 0;
}
