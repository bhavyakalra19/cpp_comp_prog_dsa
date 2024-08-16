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

int countTriangles(vector<point> points){
    int n = points.size();
    unordered_map<int,int> point_x, point_y;
    int ans = 0;
    for(int i = 0; i < n; i++){
        point_x[points[i].x]++;
        point_y[points[i].y]++;
    }

    for(int i = 0; i < n; i++){
        ans += (point_x[points[i].x] - 1) * (point_y[points[i].y] - 1);
    }
    return ans;
}

int main(){
    point p1(1,2);
    point p2(2,0);
    point p3(2,2);
    point p4(2,3);
    point p5(4,2);
    vector<point> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    cout << countTriangles(v) << endl;
    return 0;
}
