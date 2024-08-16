#include<bits/stdc++.h>
using namespace std;

vector<int> findMultipleElement(vector<int> v){
    vector<int> ans;
    int diff = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i]- i != diff){
            ans.push_back(v[i]-1);
            diff++;
        }
    }
    return ans;
}

void display(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v1 ={1,2,3,4,5,6,8,9,11,12,13,14,16,17,19,21,23,25};
    vector<int> a;
    a = findMultipleElement(v1);
    display(a);
    return 0;
}