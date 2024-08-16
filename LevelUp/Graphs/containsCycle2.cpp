#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *l;
    
    public:
        Graph(int v){
            this->v = v;
            l = new list<int>[v];
        }
        
        void addEdge(int x, int y){
            l[x].push_back(y);
        }
        
        bool dfs(int src, vector<bool> &visited, vector<bool> &stack){
            visited[src] = true;
            stack[src] = true;
            for(auto x : l[src]){
                if(stack[x]){
                    return true;
                }else if(visited[x] == false){
                    bool ans = dfs(x, visited, stack);
                    if(ans){
                        return true;
                    }
                }
            }
            stack[src] = false;
            return false;
        }
};


bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(V);
    for(int i = 0; i < edges.size(); i++){
        g.addEdge(edges[i].first,edges[i].second);
    }
    vector<bool> visited(V,false);
    vector<bool> stack(V,false);
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            bool ans = g.dfs(i,visited,stack);
            if(ans){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<pair<int,int>> v;
    v.push_back({0,1});
    v.push_back({0,4});
    v.push_back({0,5});
    v.push_back({5,4});
    v.push_back({1,2});
    v.push_back({2,3});
    v.push_back({3,0});
    if(contains_cycle(6,v)){
        cout << "This graph contains cycle" << endl;
    }
    return 0;
}