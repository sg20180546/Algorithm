#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
#define INF INT64_MAX
struct Edge{
    int s;
    int e;
    ll w;
    Edge(int start,int end, ll weight) : s(start),e(end),w(weight) {}
};

int V_N,E_N;

ll V[501];
vector <Edge> vec;

bool belman_ford(){
    int ret=false;
    for(auto e : vec){
        if(V[e.s]!=INF){
            if(V[e.s]+e.w <V[e.e]){
                ret=true;
                V[e.e]=V[e.s]+e.w;
            }
        }
    }
    return ret;
}

int main(){
    cin>>V_N>>E_N;
    for(int i=0;i<E_N;i++){
        int s,e,w;
        cin>>s>>e>>w;
        vec.emplace_back(s,e,w);
    }
    V[1]=0;
    for(int i=2;i<=V_N;i++){
        V[i]=INF;
    }


    for(int i=0;i<V_N-1;i++){
        belman_ford();
    }


    if(belman_ford()){
        cout<<-1<<"\n";
    }
    else{
        for(int i=2;i<=V_N;i++){
            // cout<<V[i]<<"\n";
            printf("%d\n",V[i]);
            // printf("%d : %d\n",i,V[i]);
        }
    }
}