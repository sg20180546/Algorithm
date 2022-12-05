#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,E,B;

struct Edge{
    int u;
    int v;
    int cost;
    bool operator < (const Edge& e){
        return cost<e.cost;
    }
};

class DisjointSet{
public:
    vector<int> parent,rank;
    DisjointSet(int vertices) : parent(vertices){
        // parent.reserve(vertices);
        // rank.reserve(vertices);
        for(int i=1;i<=vertices;i++){
            parent[i]=i;
        }
    }
    int GetParent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=GetParent(parent[i]);
    }

    void Union(int u,int v){
        u=GetParent(u);
        v=GetParent(v);

        if(u==v){
            return;
        }

        // if(rank[u]>rank[v]){
        //     swap(u,v);
        // }

        // parent[u]=v;
        // if(rank[u]==rank[v]){
        //     rank[v]++;
        // }
        if(u>v){
            parent[u]=v;
        }else{
            parent[v]=u;
        }

    }
};

int Kruskal(vector<Edge>& edge_vec){
    sort(edge_vec.begin(),edge_vec.end());

    DisjointSet sets(N+1);
    int unioned=0;
    int total_cost=0;
    for(int i=0;i<E;i++){
        int u=edge_vec[i].u;
        int v=edge_vec[i].v;
        int cost=edge_vec[i].cost;

        if(sets.GetParent(u)==sets.GetParent(v)){
            continue;
        }
        // printf("%d %d cost %d\n",u,v,cost);
        sets.Union(u,v);
        unioned++;
        total_cost+=cost;
        if(unioned==N-1){
            break;
        }
    }
    // printf("\n");
    return total_cost;
}

int main(){
    while(1){
        cin>>N>>E>>B;
        if(N==0&&E==0&&B==0){
            break;
        }
        char type;
        int u,v;
        vector<Edge> max_blue_tree(E);
        vector<Edge> min_blue_tree(E);
    
        for(int i=0;i<E;i++){
            cin>>type>>u>>v;
            
            if(type=='B'){
                max_blue_tree[i]={u,v,0};
                min_blue_tree[i]={u,v,1};
            }else{
                max_blue_tree[i]={u,v,1};
                min_blue_tree[i]={u,v,0};
            }
        }

        int max_b=(N-1)-Kruskal(max_blue_tree); // MST EDGE - # of red edge
        int min_b=Kruskal(min_blue_tree); // MST EDGE - # of blue edge
        // printf("max %d min %d\n",max_b,min_b);
        if(min_b<=B&&B<=max_b){
            cout<<"1\n";
        }else{
            cout<<"0\n";
        }
    }
}