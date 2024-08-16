#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int x;
        int y;
        int w;

        Edge(int x, int y, int w){
            this->x = x;
            this->y = y;
            this->w = w;
        }
};

class Compare{
    public:
        bool operator()(Edge a, Edge b){
            return a.w >= b.w;
        }
};

class Graph{
    public:
        int V;
        int *unionArr, *rankArr;
        priority_queue<Edge, vector<Edge>, Compare> pq; 

        Graph(int V){
            this->V = V;
            unionArr = new int[V];
            rankArr = new int[V];
            for(int i = 0; i < V; i++){
                unionArr[i] = i;
                rankArr[i] = 0;
            }
        }

        void addEdge(int x, int y, int w){
            pq.push(Edge(x,y,w));
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
                rankArr[xr] += 1;
                unionArr[yr] = xr;
            }
        }

        int kruskalAlgo(){
            int cnt = 0;
            int ans = 0;
            while(cnt < V - 1){
                auto it = pq.top();
                pq.pop();
                int cx = it.x;
                int cy = it.y;
                int cw = it.w;
                if(find(cx) != find(cy)){
                    Union(cx,cy);
                    ans += cw;
                    cnt++;
                }
            }
            return ans;
    }
};

int main(){
    int V = 9; 
    Graph g(V); 
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