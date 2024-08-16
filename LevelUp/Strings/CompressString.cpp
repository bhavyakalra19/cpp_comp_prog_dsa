#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    //complete the function to return output string
    int j = 1;
    int m = 1;
    string x = str;
    string s = "";
    for(int i = 1; i < str.length(); i++){
        if(str[i] == str[i-1]){
            j++;
            m = max(j,m);
        }else{
            s += str[i-1] + to_string(j);
            j=1;
        }
    }
    if(j > 1){
        s += str[str.length()-1] + to_string(j);
    }
    if(m == 1){
        return str;
    }
    return s;
}

int main(){
    cout << compressString("abc") << endl;
    return 0;
}