#include <iostream>
#include <queue>
using namespace std;
int N,K;
int map[2001][2001];
int parent[100001];
int unioned;
int ans;
queue <pair<int,int>> merge;
queue <pair<int,int>> spread;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int ny, int nx){
    return ny>=1&&ny<=N&& nx>=1&&nx<=N;
}

int get_parent(int i){
    if(i==parent[i]){
        return i;
    }
    return parent[i]=get_parent(parent[i]);
}

void union_parent(int u,int v){
    u=get_parent(u);
    v=get_parent(v);
    if(u==v){
        return;
    }
    unioned--;
    parent[v]=u;

}

void merge_bfs(){
    while(!merge.empty()){
        int y=merge.front().first;
        int x=merge.front().second;
        merge.pop();
        spread.push({y,x}); // ?
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(check(ny,nx)){
                if(map[ny][nx]!=0){
                    union_parent(map[ny][nx],map[y][x]);
                }
            }
        }
    }
}
void spread_bfs(){
    while(!spread.empty()){
        int y=spread.front().first;
        int x=spread.front().second;
        spread.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(check(ny,nx)){
                if(map[ny][nx]==0){
                    map[ny][nx]=map[y][x];
                    merge.push({ny,nx});
                }
            }
        }
    }
}


int main(){
    cin>>N>>K;
    for(int i=1;i<=K;i++){
        int x,y;
        cin>>x>>y;
        map[y][x]=i;
        parent[i]=i;
        merge.push({y,x});
    }
    unioned=K;
    while(1){
        merge_bfs();
        if(unioned==1){
            break;
        }
        spread_bfs();
        ans++;
    }
    cout<<ans<<"\n";
}