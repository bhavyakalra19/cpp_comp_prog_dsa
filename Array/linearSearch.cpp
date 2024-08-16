#include<bits/stdc++.h>
using namespace std;

struct Array{
    int A[20];
    int length;
    int size;
};

int linearSearch(struct Array *arr, int x){
    for(int i = 0; i< arr->length; i++){
        if(x == arr->A[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    struct Array arr = {{1,2,3,4,5,6},6};
    int index = linearSearch(&arr,12);
    if(index != -1){
        cout << "index is: " << index << endl;
    }else{
        cout << "Not found" << endl;
    }
    return 0;
}
