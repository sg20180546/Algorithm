#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define INF 300'000'000
int N,E;
int start,dest;

bool visited[1001];

struct Edge{
  int e;
  ll weight;  
};
// vector <Edge> vec;

vector <Edge> vertex[1001];
// sorted, random 

ll V[1001];
bool visisted[1001];

int get_min(){
    int w=INF;
    int ret;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            if(V[i]<w){
                ret=i;
            }
        }
    }
    // printf("ret %d\n",ret);
    visited[ret]=true;
    return ret;
}

void Djikstra(){
    for(int i=1;i<=N;i++){
        V[i]=INF;
    }
    V[start]=0;
    for(int i=0;i<N-1;i++){
        int s=get_min();
        for(auto e : vertex[s]){
            if(V[e.e]>V[s]+e.weight ){
                V[e.e]=V[s]+e.weight;
            }
        }
    }

}

int main(){
    cin>>N>>E;
    for(int i=0;i<E;i++){
        int s,e;
        ll w;
        cin>>s>>e>>w;
        vertex[s].push_back({e,w});
    }
    cin>>start>>dest;
    Djikstra();
    cout<<V[dest];
}