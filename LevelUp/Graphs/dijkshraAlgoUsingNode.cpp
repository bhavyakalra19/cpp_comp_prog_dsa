#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int nbr;
        int weight;

        Node(int x, int w){
            nbr = x;
            weight = w;
        }
};

class compare{
    public:
        bool operator()(Node *a, Node *b){
            return a->weight <= b->weight;
        }
};

class Graph{
    int V;
    list<Node*> *l;

    public:
        Graph(int v){
            V = v;
            l = new list<Node*>[V];
        }

        void addEdge(int x, int y, int w){
            Node *t1 = new Node(x,w);
            Node *t2 = new Node(y,w);
            l[x].push_back(t2);
            l[y].push_back(t1);
        }

        int dijkshtraAlgo(int src, int des){
            vector<int> dist(V,INT_MAX);
            set<Node*,compare> s;
            Node *t = new Node(src,0);
            s.insert(t);
            dist[src] = 0;
            while(!s.empty()){
                auto it = s.begin();
                s.erase(it);
                int node = (*it)->nbr;
                int currW = (*it)->weight;
                for(auto ln : l[node]){
                    int nbrNode = ln->nbr;
                    int nbrNodeW = ln->weight;
                    if(currW + nbrNodeW < dist[nbrNode]){
                        Node *temp = new Node(nbrNode,dist[nbrNode]);
                        auto fn = s.find(temp);
                        if(fn != s.end()){
                            s.erase(fn);
                        }
                        Node *temp = new Node(nbrNode,currW + nbrNodeW);
                        s.insert(temp);
                        dist[nbrNode] = currW + nbrNodeW;
                    }
                }
            }
            return dist[des];
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(2,3,2);
    g.addEdge(3,4,3);
    cout << g.dijkshtraAlgo(0,4) << endl;
    return 0;
}