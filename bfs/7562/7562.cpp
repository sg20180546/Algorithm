#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int L;
struct knight
{
    int y;
    int x;
    int move;
};


int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};

bool check(int y,int x){
    return (y>=0&&y<L&&x>=0&&x<L);
}

int bfs(){

    int destx,desty;
    int x,y;
    bool moved[400][400];
    
    queue<knight> q;

    cin>>L;
    for(int i=0;i<L;i++){
        for(int j=0;j<L;j++){
            moved[i][j]=false;
        }
    }

    cin>>x>>y;
    cin>>destx>>desty;

    q.push({y,x,0});
    moved[y][x]=true;

    while(1){
        x=q.front().x;
        y=q.front().y;
        int move=q.front().move;
        q.pop();

        if(x==destx&&y==desty){
            return move;
        }
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(check(ny,nx)&&moved[ny][nx]==false){
                q.push({ny,nx,move+1});
                moved[ny][nx]=true;
            }
        }
    }
}



int main(){
    cin.tie(); cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        cout<<bfs()<<"\n";
    }
}