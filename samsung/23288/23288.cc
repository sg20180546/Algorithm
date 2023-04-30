#include <iostream>
#include <cstring>
using namespace std;

int R,C,K;
int map[21][21];
int curx=0;
int cury=0;

int score = 0;
enum {
    LEFT,UP,RIGHT,DOWN
};

int reverse_dir[4]={RIGHT,DOWN,LEFT,UP};


int dir=RIGHT;


bool check(int y,int x){
    return y>=0&&y<R&&x>=0&&x<C;
}

int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};

int dice[7]={-1,1,2,3,4,5,6};

bool visited[21][21];

void dfs(int i, int j,int n){
    // printf("Dfs :%d %d\n",i,j);
    visited[i][j]=true;
    for(int k = 0; k<4;k++){
        int ni=i+dy[k];
        int nj=j+dx[k];
        // printf("dfs2 :%d %d\n",ni,nj);
        if(check(ni,nj)&&visited[ni][nj]==false&&map[ni][nj]==n){
            dfs(ni,nj,n);
        }
    }
}

void GetScore(){
    memset(visited,false,sizeof(visited));
    // printf("cury curx :%d %d\n",cury,curx);
    dfs(cury,curx,map[cury][curx]);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(visited[i][j]==true){
                score+=map[i][j];
            }
        }
    }
}

void ChangeDir(){
    int A=dice[6];
    int B=map[cury][curx];
    if(A>B){
        dir=(dir+1)%4;
    }else if(B>A){
        dir--;
    }
    if(dir==-1){
        dir=3;
    }
}

inline void SwapDice(int i,int j){
    int tmp=dice[i];
    dice[i]=dice[j];
    dice[j]=tmp;
}

void TurnLeft(){
    SwapDice(4,6);
    SwapDice(4,3);
    SwapDice(4,1);
}

void TurnRight(){
    SwapDice(1,4);
    SwapDice(4,6);
    SwapDice(3,6);
}

void TurnUp(){
    SwapDice(2,1);
    SwapDice(1,5);
    SwapDice(5,6);
}
void TurnDown(){
    SwapDice(5,6);
    SwapDice(1,5);
    SwapDice(1,2);
}

int main(){
    cin>>R>>C>>K;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
        }
    }
    while(K--){
        
        int ny=cury+dy[dir];
        int nx=curx+dx[dir];
        if(!check(ny,nx)){
            dir=reverse_dir[dir];
            ny=cury+dy[dir];
            nx=curx+dx[dir];
        }
        switch (dir)
        {
        case LEFT:
            TurnLeft();
            break;
        case RIGHT:
            TurnRight();
            break;
        case UP:
            TurnUp();
            break;
        case DOWN:
            TurnDown();
            break;
        default:
            break;
        }
        cury=ny;
        curx=nx;
        GetScore();
        ChangeDir();
    }
    cout<<score<<"\n";
}