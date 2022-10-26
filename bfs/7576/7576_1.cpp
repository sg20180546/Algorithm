#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>


#define MAX_SIZE 1001

using namespace std;

queue<std::pair<int,int>> q;

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
int N,M,ans;
int graph[MAX_SIZE][MAX_SIZE];

inline bool check(int ny, int nx){
    return (0<=nx&&0<=ny&&nx<M&&ny<N);
}

void bfs(void){
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
        
            if(check(ny,nx)==true&&graph[ny][nx]==0){
                graph[ny][nx]=graph[y][x]+1;
                q.push({ny,nx});    
            }
        }
        
    }
 
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>graph[i][j];
            if(graph[i][j]==1){
                q.push({i,j});
            }
        }
    } 
    bfs();
    // cout<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]==0){
                cout<<-1<<"\n";
                return 0;
            }
            if(ans<graph[i][j]){
                ans=graph[i][j];
            }
            // cout<<graph[i][j]<<" ";
        }
        // cout<<"\n";

    }

    cout<<ans-1<<"\n";
}