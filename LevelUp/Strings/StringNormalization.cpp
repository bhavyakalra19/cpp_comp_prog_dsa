#include<bits/stdc++.h>
using namespace std;


int changeWord(string &copy, int idx){
    int i = 0;
    while(idx < copy.length() && copy[idx] != ' '){
        if(i==0){
            copy[idx] = toupper(copy[idx]);
            i++;
        }else{
            copy[idx] = tolower(copy[idx]);            
        }
            idx++;
    }
    return idx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    int idx = 0;
    while(idx < copy.length()){
        if(copy[idx] == ' '){
            idx++;
        }else{
            idx = changeWord(copy,idx);   
        }
    }

    return copy;
}

int main(){
    cout << normalize("Hello my name is bhavya");
    cout << endl;
    return 0;
}