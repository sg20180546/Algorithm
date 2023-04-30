#include <iostream>
#include <assert.h>
#include <unistd.h>
using namespace std;

int N,M;
enum {
    DIRTY,WALL,CLEAN
};

enum {
    NORTH,EAST,SOUTH,WEST
};

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
enum{
    LEFT,RIGHT,FRONT,BACK
};
int direction[4][4]={
    {WEST,EAST,NORTH,SOUTH},
    {NORTH,SOUTH,EAST,WEST},
    {EAST,WEST,SOUTH,NORTH},
    {SOUTH,NORTH,WEST,EAST}
};

int cur_dir;
int cur_y;
int cur_x;
int map[51][51];

bool Check(int y, int x){
    return y>=0&&y<N&&x>=0&&x<M;
}

bool GoBack(){
    int nx;
    int ny;
    ny=cur_y+dy[direction[cur_dir][BACK]];
    nx=cur_x+dx[direction[cur_dir][BACK]];

    if(map[ny][nx]!=WALL){
        cur_y=ny;
        cur_x=nx;
        return true;
    }
    

    return false;
}
int ans=0;

bool Move(){
    int ny;
    int nx;
    int init_dir=cur_dir;
    for(int i=0;i<4;i++){
        ny=cur_y+dy[direction[cur_dir][LEFT]];
        nx=cur_x+dx[direction[cur_dir][LEFT]];

        cur_dir=direction[cur_dir][LEFT];

        if(map[ny][nx]==DIRTY){
            cur_y=ny;
            cur_x=nx;
            return true;
        }
    }
    assert(cur_dir==init_dir);
    return false;
}
int main(){
    cin>>N>>M>>cur_y>>cur_x>>cur_dir;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }

    do{
    
        if(map[cur_y][cur_x]==DIRTY){
            map[cur_y][cur_x]=CLEAN;
            ans++;
        }
        if(Move()){
            continue;
        }
        if(!GoBack()){
            break;
        }

    }while (1);
    cout<<ans<<"\n";
}