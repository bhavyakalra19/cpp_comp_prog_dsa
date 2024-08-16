#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:      
        int V, E;
        int *rankArr, *unionArr;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> Edges;
        Graph(int V, int E){
            this->V = V;
            this->E = E;
            rankArr = new int[V];
            unionArr = new int[V];
            for(int i = 0; i < V; i++){
                unionArr[i] = i;
                rankArr[i] = 0;
            }
        }

        void addEdge(int x, int y, int w){
            Edges.push({w,{x,y}});
        }

        int find(int x){
            if(unionArr[x] != x){
                unionArr[x] = find(unionArr[x]);
            }
            return unionArr[x];
        }

        void Union(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if(xr == yr){
                return;
            }

            if(rankArr[xr] < rankArr[yr]){
                unionArr[xr] = yr;
            }else if(rankArr[yr] < rankArr[xr]){
                unionArr[yr] = xr;
            }else{
                unionArr[yr] = xr;
                rankArr[xr] += 1;
            }
        }

        int kruskalAlgo(){
            int cnt = 0;
            int ans = 0;
            while(cnt < V - 1){
                auto it = Edges.top();
                Edges.pop();
                int cx = it.second.first;
                int cy = it.second.second;

                if(find(cx) != find(cy)){
                    Union(cx,cy);
                    cnt++;
                    ans += it.first;
                }
            }
            return ans;
        }
};

int main(){
    int V = 9, E = 14; 
    Graph g(V, E); 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7);
    cout << g.kruskalAlgo() << endl;
    return 0;
}