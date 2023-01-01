#include <iostream>
#include <vector>
#include <queue>
#define INF 30'000'000
using namespace std;
/*

come back : X -> u
go to : inverse direct

*/

int go[1001];
int back[1001];

vector<pair<int,int>> go_edge[1001];
vector<pair<int,int>> back_edge[1001];

int N,E,X;

int ans(){
    int ret=INT32_MIN;
    for(int i=1;i<=N;i++){
        if(go[i]+back[i]>ret){
            ret=go[i]+back[i];
        }
    }
    return ret;
}

void Dijkstra(vector<pair<int,int>> edges[1001],int *dist,int start ){
    for(int i=1;i<=N;i++){
        dist[i]=INF;
    }
    dist[start]=0;
    priority_queue<pair<int,int>> pq; //max q
    pq.push({dist[start],start});
    while(!pq.empty()){
        int distance=pq.top().first*-1; // pq first : weight
        int cur=pq.top().second; // pq second : cur vertex
        pq.pop();

        if(distance>dist[cur]) continue; // c++ cannot do decrease_key

        for(auto edge: edges[cur] ){
            int nd=(edge.second) +dist[cur]; // vec second : weight
            int next=edge.first; // vec first : 
            if(dist[next]>nd  ){
                pq.push({nd*-1,next});
                dist[next]=nd; // decrease_key(nd,next)
            }
        }
    }
}

void print(int* a){
    for(int i=1;i<=N;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    cin>>N>>E>>X;
    int s,e,w;
    for(int i=0;i<E;i++){
        cin>>s>>e>>w;
        back_edge[s].push_back({e,w});
        go_edge[e].push_back({s,w});
    }
    Dijkstra(back_edge,back,X);
    // print(back);
    Dijkstra(go_edge,go,X);
    // print(go);
    cout<<ans();
    return 0;
}

