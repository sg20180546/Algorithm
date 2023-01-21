#include <iostream>

using namespace std;

enum {
    RIGHT=1,LEFT,UP,DOWN
};

int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};

int dice[6]={0,0,0,0,0,0};
int map[23][23];
int N,M,K;


bool check(int y, int x){
    return y>=0 && y<N && x>=0 && x<M;
}

inline void swap(int i, int j){
    int tmp=dice[i];
    dice[i]=dice[j];
    dice[j]=tmp;
}

void turn_dice(int dir){
    switch (dir)
    {
    case RIGHT:
        swap(0,3);
        swap(3,2);
        swap(3,5);
        break;
    case LEFT:
        swap(0,3);
        swap(0,2);
        swap(5,2);
        break;

    case UP:
        swap(1,0);
        swap(0,4);
        swap(4,5);
        break;
    case DOWN:
        swap(4,5);
        swap(0,4);
        swap(0,1);
        break;
    default:
        break;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int x,y;
    cin>>N>>M>>y>>x>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    int dir;
    while(K--){
        cin>>dir;
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        
        if(!check(ny,nx)){
            continue;
        }
            
        turn_dice(dir);           
        x=nx;
        y=ny;
        if(map[y][x]==0){
            map[y][x]=dice[5];
            //dice[5]=0;
        }else{
            dice[5]=map[y][x];
            map[y][x]=0;
        }


        cout<<dice[0]<<"\n";   
    }
    return 0;
}