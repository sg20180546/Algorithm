#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int V,E,B;

struct Edge{
    int u;
    int v;
    int cost;
    // Edge(int u,int v,int c):u(u),v(v),cost(c) {}
    bool operator<(const Edge& e){
        return cost<e.cost;
    }
};

struct DisjointSet{
    vector<int> parent;
    DisjointSet(int N): parent(N+1){
        for(int i=1;i<=N;i++){
            parent[i]=i;
        }   
    }    
    int GetParent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=GetParent(parent[i]);
    }
    void Union(int u, int v){
        u=GetParent(u);
        v=GetParent(v);
        if(u==v){
            return;
        }
        if(u>v){
            parent[u]=v;
        }else{
            parent[v]=u;
        }
    }
};

int Kruskal(vector<Edge>& edge_vec){
    sort(edge_vec.begin(),edge_vec.end());

    DisjointSet sets(V);
    int total_cost=0;
    int connected=0;
    for(int i=0;i<E;i++){
        int cost=edge_vec[i].cost;
        int v=edge_vec[i].v;
        int u=edge_vec[i].u;
        u=sets.GetParent(u);
        v=sets.GetParent(v);
        if(u==v){
            continue;
        }
        sets.Union(u,v);
        total_cost+=cost;
        connected++;
        if(connected==V-1){
            break;
        }
    }
    return total_cost;
}

void sol(){
    cin>>V>>E>>B;
    vector<Edge> max_blue_tree(E);
    vector<Edge> min_blue_tree(E);
    if(V==0){
        exit(0);
    }
    char type;
    int v,u;
    for(int i=0;i<E;i++){
        cin>>type>>v>>u;
        if(type=='B'){
            max_blue_tree[i]={v,u,0};
            min_blue_tree[i]={v,u,1};
        }else{
            max_blue_tree[i]={v,u,1};
            min_blue_tree[i]={v,u,0};
        }
    }
    int min_blue=Kruskal(min_blue_tree);
    int max_blue=(V-1)- Kruskal(max_blue_tree);

    // cout<<min_blue<<" "<<max_blue<<"\n";
    if(min_blue<=B&&B<=max_blue){
        cout<<"1\n";
        return;
    }
    cout<<"0\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        sol();
    }
}