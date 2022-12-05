#include <iostream>
#include <vector>
using namespace std;

vector <int> child[200001];
// int parent[200001];
int root[200001];
int N,Q;


void disjoint(int x,int p){
    root[x]=p;
    for(int i=0;i<child[x].size();i++){
        root[child[x][i]]=p;
        disjoint(child[x][i],p);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>Q;
    for(int i=2;i<=N;i++){
        int p;
        cin>>p;
        child[p].push_back(i);
        // parent[i]=p;
    }
    for(int i=1;i<=N;i++) root[i]=1;
    int q,a,b;
    
    for(int i=0;i<N+Q-1;i++){
        cin>>q;
        if(q==0){
            cin>>a;
            disjoint(a,a);
        }else{
            cin>>a>>b;
            if(root[a]==root[b]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}