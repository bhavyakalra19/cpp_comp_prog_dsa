#include<bits/stdc++.h>
using namespace std;

class point{
    public:
        int x;
        int y;

        point(int x, int y){
            this->x = x;
            this->y = y;
        }
};

class compare{
    public:
        bool operator()(point p1, point p2){
            if(p1.x == p2.x){
                return p1.y < p2.y;
            }
            return p1.x < p2.x;
        }
};

int countRectangles(vector<point> points){
    int n = points.size();
    set<point,compare> s;
    
    for(auto p : points){
        s.insert(p);
    }

    int ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            point p1 = points[i];
            point p2 = points[j];
            if(p1.x == p2.x || p1.y == p2.y){
                continue;
            }
            point p3(p1.x,p2.y);
            point p4(p2.x,p1.y);
            if(s.find(p3) != s.end() && s.find(p4) != s.end()){
                ans += 1;
            }
        }
    }
    return ans/2;
}

int main(){
    point p1(0,0);
    point p2(0,1);
    point p3(1,1);
    point p4(1,0);
    point p5(2,1);
    point p6(2,0);
    point p7(3,1);
    point p8(3,0);
    vector<point> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);
    v.push_back(p8);
    cout << countRectangles(v) << endl;
    return 0;
}