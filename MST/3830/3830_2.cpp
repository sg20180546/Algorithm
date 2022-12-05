#include <iostream>

using namespace std;
typedef long long ll;
int parent[100001];
ll diff[100001];
int N,M;

int get_parent(int i){
    if(i==parent[i]){
        return i;
    }
    int root=get_parent(parent[i]);
    diff[i]+=diff[parent[i]]; //weight prev parent, change X from 0
    return parent[i]=root;
}

void union_parent(int u, int v, int w){
    int rootu=get_parent(u);
    int rootv=get_parent(v);

    if(rootu==rootv){
        return;
    }

    diff[rootv]=diff[u]+w-diff[v];

    parent[rootv]=rootu;
}

void sol(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    if(N==0){
        exit(0);
    }
    for(int i=1;i<=N;i++){
        parent[i]=i;
        diff[i]=0;
    }
    char type;
    ll a,b,w;
    for(int i=0;i<M;i++){
        cin>>type;
        if(type=='!'){
            cin>>a>>b>>w;
            union_parent(a,b,w);
        }else{
            cin>>a>>b;
            if(get_parent(a)==get_parent(b)){
                cout<<diff[b]-diff[a]<<"\n";
            }else{
                cout<<"UNKNOWN\n";
            }
        }
    }
}

int main(){
    while(1){
        sol();
    }
    return 0;
}

