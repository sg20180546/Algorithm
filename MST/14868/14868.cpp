#include <iostream>
#include <queue>
using namespace std;
/*
BFS+MST
https://akim9905.tistory.com/25
*/
queue <pair<pair<int,int>,pair<int,int>>> q;

int parent[100001];
int map[2001][2001];

int N,K,ans;
int civil;
int dy[]={-1,0,0,1};
int dx[]={0,1,-1,0};

int getparent(int i){
    if(i==parent[i]){
        return i;
    }
    return parent[i]=getparent(parent[i]);
}
void union_p(int u,int v){
    u=getparent(u);
    v=getparent(v);
    if(u==v){
        return;
    }
    civil--;
    if(u<v){
        parent[u]=v;
    }else{
        parent[v]=u;
    }
}

// bool test(){
//     int candidate=getparent(1);
//     for(int i=2;i<=K;i++){
//         if(getparent(i)!=candidate){
//             // printf("%d %d \n",i,getparent(i));
//             return false;
//         }
//     }
//     return true;
// }
inline bool canmove(int ny,int nx){
    return (ny>=1&&nx>=1&&ny<=N&&nx<=N);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>K;
    int y,x;
    for(int i=1;i<=K;i++){
        parent[i]=i;
        cin>>x>>y;
        q.push({{i,0},{y,x}});
        map[y][x]=i;
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++)
    //         printf("%d ",map[i][j]);
    //     printf("\n");
    // }
    civil=K;
    while(1){
        int y=q.front().second.first;
        int x=q.front().second.second;
        int p=q.front().first.first;
        int cost=q.front().first.second;
        map[y][x]=p;
        // printf("y : %d x: %d cost %d\n",y,x,cost);
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(canmove(ny,nx)){
                if(map[ny][nx]!=0){
                    union_p(map[ny][nx],map[y][x]);
                }else{
                    q.push({{p,cost+1},{ny,nx}});
                    // map[ny][nx]=map[y][x];   
                }
            }
        }
        // if(prevcost!=cost ){
        //     prevcost=cost;
            // if(test()){
            //     break;
            // }
        // }

        ans=cost;
        if(civil==1){
            break;
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++)
    //         printf("%d ",getparent(map[i][j]));
    //     printf("\n");
    // }
    cout<<ans<<"\n";
    return 0;
}
