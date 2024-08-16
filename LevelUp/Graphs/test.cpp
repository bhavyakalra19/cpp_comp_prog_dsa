#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V;
        list<pair<int,int>> *l;

        Graph(int V){
            this->V = V;
            l = new list<pair<int,int>>[V];
        }

        void addEdge(int a, int b, int w){
            l[a].push_back({b,w});
            l[b].push_back({a,w});
        }

        vector<int> dijkstraAlgo(){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            vector<int> dist(V,INT_MAX);
            dist[0] = 0;
            pq.push({0,0});
            while(!pq.empty()){
                auto it = pq.top();
                pq.pop();
                for(auto num: l[it.second]){
                    if((num.second + it.first) < dist[num.first]){
                        dist[num.first] = num.second + it.first;
                        pq.push({num.second + it.first,num.first});
                    }
                }
            }
            return dist;
        }
};

int main(){
    Graph g(6);
    g.addEdge(0,1,1);
    g.addEdge(0,3,8);
    g.addEdge(1,2,2);
    g.addEdge(1,5,1);
    g.addEdge(2,5,3);
    g.addEdge(2,4,2);
    g.addEdge(5,4,10);
    g.addEdge(3,4,1);
    g.addEdge(2,3,2);
    vector<int> dist;
    dist = g.dijkstraAlgo();
    for(auto a : dist){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}