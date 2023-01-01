#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
#define INF 30'000'000
// https://4z7l.github.io/2021/03/04/algorithms-boj-1865.html
struct Edge{
    int s;
    int e;
    ll w;
    Edge(int start,int end, ll weight) : s(start),e(end),w(weight) {}
};
vector<Edge> vec;
int TC;

ll V[503];

bool bellman_ford(){
    int ret=false;
    for ( auto edge : vec){
            // relaxing
            if(V[edge.e]>V[edge.s]+edge.w ){
                ret=true;
                V[edge.e]=V[edge.s]+edge.w;
            }
    }
    return ret;
}

void sol(){
    int V_N,R,W;
    cin>>V_N>>R>>W;
    vec.clear();
    // if(vec.size()!=0){
    //     printf("%s",0);
    // }
    ll s,e,t;
    for(int i=0;i<R;i++){
        cin>>s>>e>>t;
        vec.emplace_back(s,e,t);
        vec.emplace_back(e,s,t);
    }
    for(int i=0;i<W;i++){
        cin>>s>>e>>t;
        vec.emplace_back(s,e,-t);
    }

    // V[1]=0;
    for(int i=1;i<=V_N;i++){
        V[i]=INF;
    }
    for(int i=0;i<V_N-1;i++){
        bellman_ford();
    }
    // for(auto edge: vec){
    //     if(V[edge.e]>V[edge.s]+edge.w){
    //         cout<<"YES\n";
    //         return;
    //     }
    // }
    // cout<<"NO\n";

    
    if(bellman_ford()){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>TC;
    for(int i=0;i<TC;i++){
        sol();
    }

}