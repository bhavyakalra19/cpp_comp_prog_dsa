#include<bits/stdc++.h>
using namespace std;

class cabs{
    public:
        int x, y;
        string name;
        cabs(int x, int y, string name){
            this->x = x;
            this->y = y;
            this->name = name;
        }

        int distance(){
            return sqrt(x*x + y*y);
        } 
};

class cabsCompare{
    public:
        bool operator()(cabs a, cabs b){
            return a.distance() < b.distance();
        }
};

void closestCabs(vector<cabs> nums, int k){
    vector<string> v;
    priority_queue<cabs, vector<cabs>, cabsCompare> disHeap(nums.begin(), nums.begin() + k);

    for(int i = k; i < nums.size(); i++){
        if(((cabs)disHeap.top()).distance() > nums[i].distance()){
            disHeap.pop();
            disHeap.push(nums[i]);
        }
    }

    while(!disHeap.empty()){
        v.push_back(disHeap.top().name);
        disHeap.pop();
    }
    reverse(v.begin(),v.end());
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    cabs c1(1,1,"C1");
    cabs c2(2,1,"C2");
    cabs c3(3,2,"C3");
    cabs c4(1,0,"C4");
    vector<cabs> v;
    v.push_back(c1);
    v.push_back(c2);
    v.push_back(c3);
    v.push_back(c4);
    closestCabs(v,2);
    return 0;
}