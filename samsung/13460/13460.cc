#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N,M;
enum {
    LEFT,RIGHT,UP,DOWN
};

int dy[]={0,0,-1,1};
int dx[]={-1,1,0,0};

vector<string> map;
bool possible=false;
int ans=INT32_MAX;

void Reset(int r_y,int r_x,int b_y,int b_x){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]=='R'||map[i][j]=='B'){
                map[i][j]='.';
            }
        }
    }
    map[r_y][r_x]='R';
    map[b_y][b_x]='B';
}
/*
5 5
#####
#..B#
#.#.#
#RO.#
#####
*/

bool Move(int dir,int& y,int& x,char color){
    
    int ny=y+dy[dir];
    int nx=x+dx[dir];
    map[y][x]='.';

    while(map[ny][nx] != '#' && map[ny][nx]!='R' && map[ny][nx]!='B'){
        if(map[ny][nx]=='O'){
            return true;
        }
        ny=ny+dy[dir];
        nx=nx+dx[dir];
    }
    y=ny-dy[dir];
    x=nx-dx[dir];
    map[y][x]=color;
    
    return false;
}

void Play(int try_n,int& r_y,int& r_x, int& b_y,int& b_x){
    bool red_in_hole;
    bool blue_in_hole;
    if(try_n>10){
        return;
    }
    int reset_r_y=r_y;
    int reset_r_x=r_x;
    int reset_b_y=b_y;
    int reset_b_x=b_x;

    for(int dir=0;dir<4;dir++){
        Reset(reset_r_y,reset_r_x,reset_b_y,reset_b_x);
        r_y=reset_r_y;
        r_x=reset_r_x;
        b_y=reset_b_y;
        b_x=reset_b_x;
        for(int i=0;i<2;i++){
            red_in_hole=Move(dir,r_y,r_x,'R');
            blue_in_hole=Move(dir,b_y,b_x,'B');
        }
        if(blue_in_hole){
            continue;
        }
        if(red_in_hole){
            possible=true;
            if(ans>try_n){
                ans=try_n;
            }
            continue;
        }
        Play(try_n+1,r_y,r_x,b_y,b_x);
    }

}

int main(){
    cin>>N>>M;
    int r_x;
    int r_y;
    int b_x;
    int b_y;

    map.assign(N,string());
    for(int i=0;i<N;i++){
        cin>>map[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]=='R'){
                r_y=i;
                r_x=j;
            }
            if(map[i][j]=='B'){
                b_y=i;
                b_x=j;
            }
        }
    }

    Play(1,r_y,r_x,b_y,b_x);

    if(possible){
        cout<<ans<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}
