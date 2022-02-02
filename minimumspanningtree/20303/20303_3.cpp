#include <iostream>

using namespace std;

int N,M,K;

int candy[30010];
int parent[30010];
int dp[3010];
int friends[30010];
int get_parent(int x){
    if(x==parent[x]) return x;
    else return parent[x]=get_parent(parent[x]);
}

void union_parent(int x, int y){
    x=get_parent(x);
    y=get_parent(y);
    if(x<y) parent[y]=x;
    else parent[x]=y;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        cin>>candy[i];
    }
    for(int i=1;i<=N;i++){
        parent[i]=i;
        friends[i]=1;
    }
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        union_parent(a,b);
    }
    for(int i=1;i<=N;i++){
        // if i is other friends
        if(parent[i]!=i){
            //??d
            int p =get_parent(i);
            friends[p]++;
            candy[p]+=candy[i];
        }
    }
    for(int i=1;i<=N;i++){
        if(parent[i]!=i) continue;
//  important
        for(int j=K-1;j-friends[i]>=0;j--){
            dp[j]=max(dp[j],dp[j-friends[i]]+candy[i] );
        }
    }

    cout<<dp[K-1];

    return 0;
}