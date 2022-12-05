#include <iostream>
#define UNKNOWN -5
using namespace std;
long long diff[100001];
int parent[100001];
int N,M;

int get_parent(int i){
    if(i==parent[i]){
        return i;
    }
    int p=get_parent(parent[i]);
    diff[i]+=diff[parent[i]];
    return parent[i]=p;
}

void union_parent(int v,int u,int weight){
    int vp=get_parent(v);
    int up=get_parent(u);
    // printf("%d %d\n",vp,up);
    if(vp==up){
        return;
    }


    diff[up]=diff[v]+weight-diff[u];
    parent[up]=vp;
}

bool f(){
    cin>>N>>M;
    
    if(N==0&&M==0){
        return false;
    }
    for(int i=1;i<=N;i++){
        diff[i]=0;
        parent[i]=i;
    }
    // int m=0;
    char type;
    int v,u,w;
    for(int m=0;m<M;m++){
        cin>>type;
        if(type=='!'){
            cin>>v>>u>>w;
            union_parent(v,u,w);
        }else{
            cin>>v>>u;
            if(get_parent(v)!=get_parent(u)){
                cout<<"UNKNOWN\n";
            }else{
                cout<<diff[u]-diff[v]<<"\n";
            }
        }
    }
    return true;

}

int main(){
    while(f());
}