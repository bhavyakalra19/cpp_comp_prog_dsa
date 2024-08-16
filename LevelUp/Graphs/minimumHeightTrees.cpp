#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V;
        vector<int> inDegree;
        list<int> *l;

        Graph(int V){
            this->V = V;
            l = new list<int>[V];
            inDegree.resize(V,0);
        }

        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
            inDegree[x] += 1;
            inDegree[y] += 1;
        }

        vector<int> minHeight(vector<vector<int>> nums){
            int n = nums.size();
            int level = 0;
            unordered_map<int,vector<int>> mp;
            queue<int> q;
            for(int i = 0; i < n; i++){
                addEdge(nums[i][0],nums[i][1]);
            }

            for(int i = 0; i < V; i++){
                if(inDegree[i] == 1){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int n = q.size();
                for(int i = 0; i < n; i++){
                    int idx = q.front();
                    q.pop();
                    inDegree[idx] -= 1;
                    mp[level].push_back(idx);
                    for(auto x : l[idx]){
                        inDegree[x] -= 1;
                        if(inDegree[x] == 1){
                            q.push(x);
                        }
                    }
                }
                level++;
            }
            return mp[mp.size() - 1];
        }
};

int main(){
    vector<vector<int>> nums{{3,0},{3,1},{3,2},{3,4},{5,4}};
    Graph g(6);
    vector<int> v = g.minHeight(nums);
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}