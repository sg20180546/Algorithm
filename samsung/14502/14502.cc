#include <iostream>
#include <vector>
#include <queue>
using namespace std;
enum{
    VOID,WALL,VIRUS
};
int N,M;
int ans=0;
int map[10][10];
int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

bool Check(int y, int x){
    return y>=0&&y<N&&x>=0&&x<M;
}

vector<pair<int,int>> virus;

void printmap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    printf("\n");
}

void BFS(){
    queue<pair<int,int>> q;

    while(!q.empty()){
        q.pop();
    }
    
    for(auto v : virus){
        q.push(v);
        // map[v.first][v.second]=VIRUS;
    }
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(Check(ny,nx) && map[ny][nx]==VOID){
                map[ny][nx]=VIRUS;
                q.push({ny,nx});
            }
        }

    }

    int tmp=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==VOID){
                tmp++;
            }
        }
    }

    if(tmp>ans){
        // printf("tmp : %d\n",tmp);
        // printmap();
        ans=tmp;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==VIRUS){
                map[i][j]=VOID;
            }
        }
    }
    for(auto v : virus){
        map[v.first][v.second]=VIRUS;
    }
}

void sol(int idx,int y, int x){
    
    if(idx==3){
        BFS();
        return;
    }

    
    for(int i=y; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            if(map[i][j]==VOID){
                map[i][j]=WALL;
                sol(idx+1,i,j);
                map[i][j]=VOID;
            }

        }
    }

}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==VIRUS){
                virus.emplace_back(i,j);
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            sol(0,i,j);
        }
    }
    cout<<ans<<"\n";
}