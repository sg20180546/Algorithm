#include <iostream>
#include <cstring>
using namespace std;

// 
int ans = 0;
int dy[]={-1,-1, 0, 1, 1, 1, 0,-1};
int dx[]={ 0,-1,-1,-1, 0, 1, 1, 1};

struct Fish{
    int n;
    int dir;
    bool live=true;
};
Fish map[5][5];
Fish map_tmp[5][5];
void PrintN(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(map[i][j].live){
                printf("%3d ",map[i][j].n);
            }else{
                printf("%3d ",-1);
            }
        }
        printf("\n");
    }
    printf("\n");
    // printf("shark at %d %d\n",sy ,sx);
}

bool check(int y, int x){
    return x>=0&&x<4&&y>=0&&y<4;
}

void FishMove(int sharky,int sharkx){

    for(int n=1;n<=16;n++){
        bool flag= false;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(map[i][j].n != n){
                    continue;
                }
                if(map[i][j].live==false){
                    continue;
                }

                int ny,nx,nd=map[i][j].dir;
                for(int d=0;d<8;d++){
                    nd=(map[i][j].dir+d)%8;
                    ny=i+dy[nd];
                    nx=j+dx[nd];

                    if(check(ny,nx) ){
                        if(!(ny==sharky&&nx==sharkx)){
                            flag=true;
                        }
                    }
                    if(flag) break;
                }

                map[i][j].dir=nd;

                Fish tmp=map[ny][nx];
                map[ny][nx]=map[i][j];
                map[i][j]=tmp;
                break;
            }
            if(flag) break;
        }
    }

}

void SharkMove(int sy,int sx,int sdir,int score){
    ans=max(score,ans);
    Fish tmp[5][5];

    memcpy(tmp,map,sizeof(map));

    map[sy][sx].live=false;
    FishMove(sy,sx);

    int ret = score;
    for(int d=1;d<=3;d++){

        int ny=sy+dy[sdir]*d;
        int nx=sx+dx[sdir]*d;
        if(check(ny,nx)&&map[ny][nx].live==true){
            SharkMove(ny,nx, map[ny][nx].dir, score+map[ny][nx].n);
        }
    }
    memcpy(map,tmp,sizeof(map));
}

int main(){

    int sharkx,sharky,sharkdir,score;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int d;
            int n;
            scanf("%d %d",&n,&d);
            map[i][j].dir=d-1;
            map[i][j].n=n;
        }
    }

    map[0][0].live=false;
    // sharkx=0; sharky=0;
    // sharkdir=map[0][0].dir;
    // score=map[0][0].n;

    // FishMove(0,0);
    // PrintN();
    // memcpy(map_tmp,map,sizeof(map));


    // for(int d = 1 ;d<=3;d++){
    //     // memcpy(map,map_tmp,sizeof(map));
    //     int ny=sharky+dy[sharkdir]*d;
    //     int nx=sharkx+dx[sharkdir]*d;

    //     if(check(ny,nx)&&map[ny][nx].live==true){
    //         int ret = SharkMove(ny,nx,map[0][0].dir,map[0][0].n);
    //         if(ret>ans){
    //             ans=ret;
    //             // PrintN();
    //         }
    //     }
    // }
    SharkMove(0,0,map[0][0].dir,map[0][0].n);
    printf("%d\n",ans);
    return 0;
}