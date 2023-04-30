#include <iostream>
#include <cstring>
using namespace std;

// int sharkx,sharky,sharkdir;
int ans = 0;
int dy[]={-1,-1,0,1,1,1,0,-1};
int dx[]={0,-1,-1,-1,0,1,1,1};

struct Fish{
    int n;
    int dir;
    bool live=true;
};
Fish map[5][5];
Fish map_tmp[5][5];


bool check(int y, int x){
    return x>=0&&x<4&&y>=0&&y<4;
}


void PrintN(int sy ,int sx){
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
    printf("shark at %d %d\n",sy ,sx);
}

void PrintDir(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(map[i][j].live){
                printf("%3d ",map[i][j].dir);
            }else{
                printf("%3d ",-1);
            }
        }
        printf("\n");
    }
    printf("\n");
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
                    nd=(nd+d)%8;
                    ny=i+dy[nd];
                    nx=j+dx[nd];

                    if(check(ny,nx) ){
                        if(!(ny==sharky&&nx==sharkx)){
                            break;
                        }
                    }
                }

                flag=true;
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

int SharkMove(int distance,int score,int sy, int sx,int sdir,int index){

    Fish tmp[5][5];


    map[sy][sx].live=false;
    sdir=map[sy][sx].dir;
    score+=map[sy][sx].n;
    int ret=score;
    int cmp=0;

    if(index==0){
        FishMove(sy,sx);
    }

    memcpy(tmp,map,sizeof(map));

    int ny=sy+dy[sdir]*distance;
    int nx=sx+dx[sdir]*distance;

    if(check(ny,nx)&&map[ny][nx].live==true ){
        for(int k=1;k<=3;k++){
            // printf("------------\n");
            // PrintN(sy,sx);
            FishMove(sy,sx);

            cmp=SharkMove(k,score,ny,nx,sdir,index+1);
            if(cmp>ret){
                ret=cmp;
            }
            memcpy(map,tmp,sizeof(map));
            // PrintN(sy,sx);
            // printf("------------\n");
        }
    }
    
    return ret;
}


int main(){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int d;
            int n;
            scanf("%d %d",&n,&d);
            map[i][j].dir=d-1;
            map[i][j].n=n;
        }
    }

    memcpy(map_tmp,map,sizeof(map));
    for(int d = 1 ;d<=3;d++){
        memcpy(map,map_tmp,sizeof(map));

        int ret =SharkMove(d,0,0,0,0,0);
        printf("%d ::%d\n\n",d,ret);
        if(ret>ans){
            ans=ret;
        }
    }
    printf("%d\n",ans);
    return 0;
}