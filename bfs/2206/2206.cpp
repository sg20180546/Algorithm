#include <iostream>
#include <string>
using namespace std;

int map[1001][1001];
int N,M;
int ans;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int nx, int ny){
    return (nx>=0 && ny>=0 && nx<M && ny<N && map[ny][nx]==0);
}

void dfs(int y,int x,int move){
    if(x==M-1&&y==N-1){
        if(move<ans){
            ans=move;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(check(nx,ny)==true){
            // printf("no here\n");
            // printf("%d %d, %d\n",ny,nx,map[ny][nx]);
            map[y][x]=1;
            dfs(ny,nx,move+1);
            map[y][x]=0;
        }
    }


}

int main(){
    // cin.tie(); cout.tie(0);
    // ios::sync_with_stdio(false);
    // printf("??");
    string s;
    cin>>N>>M;
    ans=INT32_MAX;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<M;j++){
            if(s[j]=='1'){
                map[i][j]=1;
            }else{
                map[i][j]=0;
            }
        }
    }
    dfs(0,0,1);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1){
                map[i][j]=0;
                dfs(0,0,1);
                map[i][j]=1;
            }
            // printf("map")
        }
    }
    if(ans==INT32_MAX){
        ans=-1;
    }
    cout<<ans<<"\n";
}