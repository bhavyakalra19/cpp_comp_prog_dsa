#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        string name;
        list<string> nbrs;

        Node(string name){
            this->name = name;
        }
};

class Graph{
    public:
        unordered_map<string,Node*> mp;
        Graph(vector<string> v){
            for(int i = 0; i < v.size(); i++){
                mp[v[i]] = new Node(v[i]);
            }
        }

        void addEdge(string x, string y, bool uni = false){
            mp[x]->nbrs.push_back(y);
            if(uni){
                mp[y]->nbrs.push_back(x);
            }
        }

        void printData(){
            for(auto m : mp){
                cout << m.second->name << "->";
                for(auto x : m.second->nbrs){
                    cout << x << ",";
                }
                cout << endl;
            }
        }
};

int main(){
    vector<string> v{"London","NewYork","China","India"};
    Graph g(v);
    g.addEdge("NewYork","India");
    g.addEdge("India","London");
    g.addEdge("London","China");
    g.addEdge("China","NewYork");
    g.printData();
    return 0;
}