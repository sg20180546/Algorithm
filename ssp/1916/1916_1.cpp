#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define INF 300'000'000
int N,E;
int start,dest;
struct Edge{
    ll weight;
    int end;
};

ll V[1001];
vector <Edge> vertex[1001];

priority_queue<pair<int,int>> pq;

void Djikstra(void){
    for(int i=1;i<=N;i++){
        V[i]=INF;
    }
    V[start]=0;
    pq.push({V[start],start});
    while(!pq.empty()){
        int dist=pq.top().first*-1;
        int cur=pq.top().second;
        pq.pop();
        if(V[cur]<dist) continue;

        for(auto edge: vertex[cur]){ // for u in adj[v,u]
            int next=edge.end; // u 
            int weight=edge.weight; // e.w
            if(V[next] > weight+V[cur]){ // u.d > e.w + v.d
                pq.push({(weight+V[cur])*-1 ,next});
                V[next]=weight+V[cur];
            }
        }
    }
}

int main(){
    cin>>N>>E;

    for(int i=0;i<E;i++){
        int s,e,w;
        cin>>s>>e>>w;
        vertex[s].push_back({w,e});
    }
    cin>>start>>dest;
    Djikstra();
    cout<<V[dest];
}