#include <iostream>

using namespace std;

// dfs , time out
int N,M;
int field[1001][1001];
int date[1001][1001];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
void dfs(int y,int x,int day){

    if(date[y][x]>day){
        date[y][x]=day;
    }
    
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||field[ny][nx]==1||ny>=N||nx>=M||field[ny][nx]==-1){
            continue;
        }
        field[ny][nx]=1;
        dfs(ny,nx,day+1);
        field[ny][nx]=0;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>field[i][j];
            // if(field[i][j]==1){}
            date[i][j]=INT32_MAX;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            if(field[i][j]==1){
                dfs(i,j,0);
            }
        }
    }
    // cout<<"\n";
    int ans=INT32_MIN;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(field[i][j]!=-1&&date[i][j]==INT32_MAX){
                cout<<-1<<"\n";
                return 0;
            }
            if(field[i][j]!=-1&&ans<date[i][j]){
                ans=date[i][j];
            }
            // cout<<date[i][j]<<" ";
        }
        // cout<<"\n";
    }
    cout<<ans<<"\n";
}