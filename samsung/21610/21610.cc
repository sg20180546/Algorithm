#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M;

int dy[]={0, 0,-1,-1,-1, 0, 1, 1, 1};
int dx[]={0,-1,-1, 0, 1, 1, 1, 0,-1};

bool check(int y, int x){
    return y>=0&&y<N&&x>=0&&x<N;
}

struct Cell{
    bool cloud=false;
    int water;
};

struct Magic{
    int dir;
    int dis;
};
Cell map[51][51];
bool map_tmp[51][51];
vector<Magic> magics;

void PrintCloud(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",map_tmp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void PrintWater(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",map[i][j].water);
        }
        printf("\n");
    }
    printf("\n");
}

void InitTmp(){
    memset(map_tmp,false,sizeof(map_tmp));
}

void Move(Magic m){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j].cloud==false){
                continue;
            }
            int y=i; int x=j;
            int ny,nx;
            for(int k=0;k<m.dis;k++){
                ny=y+dy[m.dir];
                nx=x+dx[m.dir];
                if(ny<0){
                    ny=N-1;
                }
                if(ny>=N){
                    ny=0;
                }
                if(nx<0){
                    nx=N-1;
                }
                if(nx>=N){
                    nx=0;
                }
                y=ny;
                x=nx;
            }
            map_tmp[y][x]=true;
            map[y][x].water++;
        }
    }
}

void WaterCopy(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map_tmp[i][j]==false){
                continue;
            }
            int d=0;
            for(int k=2;k<9;k+=2){
                int y=i+dy[k];
                int x=j+dx[k];
                if(check(y,x) && map[y][x].water){
                    d++;
                }
            }
            map[i][j].water+=d;
        }
    }
}

void NewCloud(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j].cloud=false;
            if(map_tmp[i][j]==false&&map[i][j].water>=2){
                map[i][j].water-=2;
                map[i][j].cloud=true;
            }
        }
    }
}

int Answer(){
    int ret =0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ret+=map[i][j].water;
    return ret;
}

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j].water);
        }
    }
    while(M--){
        int dir,dis;
        scanf("%d %d",&dir,&dis);
        magics.push_back({dir,dis});
    }
    map[N-1][0].cloud=true;
    map[N-1][1].cloud=true;
    map[N-2][0].cloud=true;
    map[N-2][1].cloud=true;
    for(auto m: magics){

        InitTmp();
        Move(m);
        // PrintCloud();
        // PrintWater();
        WaterCopy();
        // PrintWater();
        NewCloud();
    }
    printf("%d\n",Answer());
}