#include <iostream>
#include <stack>

using namespace std;

const int MAX_N=2e5+3;
stack <bool> ans;
int N,Q;
int parent[MAX_N];
int pnode[MAX_N];
int n1[MAX_N*2],n2[MAX_N*2];

int get_parent(int x){
    if(x==parent[x]) return x;
    else return parent[x]=get_parent(parent[x]);
}
void union_parent(int x,int y){
    x=get_parent(x);
    y=get_parent(y);
    if(x>y) parent[x]=y;
    // if(x==y) return;
    else parent[y]=x;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    // printf("%d",MAX_N);
    cin>>N>>Q;
    parent[1]=1;

    for(int i=2;i<=N;i++){
        cin>>pnode[i];
        parent[i]=i;
    }
    
    int x;
    for(int i=1;i<=N+Q-1;i++){
        cin>>x;
        if(x){
            cin>>n1[i]>>n2[i];
        }else{
            cin>>n1[i];
        }
    }
    for(int i=N+Q-1;i>0;i--){
        if(n2[i]){
            if( get_parent(n1[i])==get_parent(n2[i]) ) ans.push(1);
            else ans.push(0);
        }else{
            union_parent(n1[i], pnode[n1[i]]);
        }
    }

    while( !ans.empty() ){
        if(ans.top()) cout<<"YES\n";
        else cout<<"NO\n";
        ans.pop();
    }

    return 0;
}