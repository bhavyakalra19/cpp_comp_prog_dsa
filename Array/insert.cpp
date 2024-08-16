#include<bits/stdc++.h>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array *arr){
    for(int i=0; i< arr->length;i++){
        cout << arr->A[i] << " ";
    }
    cout << endl;
}

void append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x; // arr length will increase after intialization
    }
    cout << arr->length << endl; 
}

void insert(struct Array *arr, int index, int x){
    if(index>=0 && index <= arr->length){
        for(int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
    }
}

int main(){
    struct Array arr = {{1,2,3,4,5,6},10,6};
    display(&arr);
    append(&arr, 7);
    display(&arr);
    insert(&arr,4,10);
    display(&arr);
    return 0;
}