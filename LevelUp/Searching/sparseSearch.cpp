#include<bits/stdc++.h>
using namespace std;

int sparseSearch(vector<string> v, string str){
    int n = v.size();
    int s = 0;
    int e = n - 1;
    int mid;
    while(s <= e){
        int mid = (s + e)/2;
        if(v[mid] == ""){
            int left = mid - 1;
            int right = mid + 1;
            while(1){
                if(left < s && right > e){
                    return -1;
                }
                if(left >= s && v[left] != ""){
                    mid = left;
                    break;
                }else if(right <= e && v[right] != ""){
                    mid = right;
                    break;
                }
                left--;
                right++;
            }
        }
        if(v[mid] == str){
            return mid;
        }else if(v[mid] > str){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<string> v{"a", "", "", "ab", "" ,"", "absa", "", "", "bat","", "", "", ""};
    cout << sparseSearch(v,"bat") << endl;
    return 0;
}