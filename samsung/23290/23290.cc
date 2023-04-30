#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
#define SIZE 5
int fish_n,shark_play;
enum {
    SW,S,SE,E,NE,N,NW,W
};

int dy[]={ 1, 1, 1, 0,-1,-1,-1, 0};
int dx[]={-1, 0, 1, 1, 1, 0,-1,-1};

/*
1->7
6->2
*/
struct Fish{
    int y;
    int x;
    int dir;
};

int shark_y;
int shark_x;

vector<Fish> copies;
struct Cell{
    bool smell=false;
    int fish_dead_turn;
    vector<Fish> fishes;
};


Cell map[SIZE][SIZE];


void PrintMap(){
    return;
    for(int i =1;i<SIZE;i++){
        for(int j=1;j<SIZE; j++){
            printf("[%d][%d] smell : %d :: ",i,j,map[i][j].smell);
            for(auto f : map[i][j].fishes){
                printf("%d %d %d // ",f.y,f.x,f.dir);
            }
            printf("\n");
        }
        
    }
    printf("shark at :%d %d\n\n",shark_y,shark_x);
}

void CopyFish1(vector<Fish>& dest){
    dest.clear();
    for(int i=1;i<SIZE;i++){
        for(int j=1;j<SIZE;j++){
            for(auto f : map[i][j].fishes){
                dest.push_back(f);
            }
        }
    }
}
void CopyFish2(){
    for(auto f : copies){
        // printf("copy2 at %d %d %d\n",f.y,f.x,f.dir);
        map[f.y][f.x].fishes.push_back(f);
    }
}

bool Check(int y ,int x){
    return y>=1&&y<SIZE&&x>=1&&x<SIZE;
}

void MoveFish(Fish& fish){
    int ny,nx;
    int dir=fish.dir;
    for(int i=0;i<8;i++){
        dir=(fish.dir+i)%8;
        ny=fish.y+dy[dir];
        nx=fish.x+dx[dir];
        if(shark_y==ny&&shark_x==nx){
            continue;
        }
        if(Check(ny,nx) && map[ny][nx].smell==false){
            // printf("%d : %d %d %d->move to %d %d %d\n",i,fish.y,fish.x,fish.dir,ny,nx,dir);
            fish.y=ny;
            fish.x=nx;
            fish.dir=dir;
            return;
        }
    }
    // assert(fish.dir+1==init_dir);
    // fish.dir=init_dir;
}

void MoveFishes(){
    vector<Fish> fish;
    CopyFish1(fish);
    // printf("movefish size 0 :%d\n",fish.size());
    for(int i=0;i<fish.size();i++){
        MoveFish(fish[i]);
    }
    // printf("movefish size 1 :%d\n",fish.size());
    for(int i=1;i<SIZE;i++){
        for(int j=1;j<SIZE;j++){
            map[i][j].fishes.clear();
        }
    }
//  printf("movefish size 2 :%d\n",fish.size());
    for(auto f : fish){
        map[f.y][f.x].fishes.push_back(f);
    }
}
// UP LEFT DOWN RIGHT
int s_dy[]={-1,0,1,0};
int s_dx[]={0,-1,0,1};
int opt_fish_n;
void SharkBestWay(int idx,int y,int x,int fish_n,string& candidate,string& opt){
    int ny,nx,f;
    vector<Fish> catcehd_fish;
    catcehd_fish.clear();
    if(idx==3){
        
        if(fish_n > opt_fish_n){
            // printf("fish_n : %d, %s\n",fish_n,candidate.c_str());
            opt_fish_n=fish_n;
            opt=candidate;

        }
        else if(fish_n==opt_fish_n){
            if(candidate<opt){
                // printf("fish_n : %d, %s\n",fish_n,candidate.c_str());
                opt=candidate;
            }
        }

        return;
    }

    for(int i=0;i<4;i++){
        ny=y+s_dy[i];
        nx=x+s_dx[i];
        if(Check(ny,nx)){
            catcehd_fish.clear();
            f=fish_n+map[ny][nx].fishes.size();
            // printf("%d %d %ld\n",ny,nx,map[ny][nx].fishes.size());
            for(auto f : map[ny][nx].fishes){
                catcehd_fish.push_back(f);
            }
            map[ny][nx].fishes.clear();
            candidate.push_back(i+'0');

            SharkBestWay(idx+1,ny,nx,f,candidate,opt);

            for(auto f : catcehd_fish){
                map[ny][nx].fishes.push_back(f);
            }
            candidate.pop_back();
        }
    }
}

void MoveShark(int turn){
    string opt_move="333";
    int dir;

    string candidate;
    candidate.clear();
    opt_fish_n=0;
    SharkBestWay(0,shark_y,shark_x,0,candidate,opt_move);
    // std::cout<<"opt move : " <<opt_move<<"\n\n";
    for(int i=0;i<3;i++){
        dir=opt_move[i]-'0';
        shark_y+=s_dy[dir];
        shark_x+=s_dx[dir];
        if(map[shark_y][shark_x].fishes.size()){
            map[shark_y][shark_x].smell=true;
            map[shark_y][shark_x].fish_dead_turn=turn;
        }
        map[shark_y][shark_x].fishes.clear();
    }
}

void SmellDisappear(int turn){
    for(int i=1;i<SIZE;i++){
        for(int j=1;j<SIZE;j++){
            if(map[i][j].smell==true&& turn - map[i][j].fish_dead_turn==2 ){
                map[i][j].smell=false;
            }
        }
    }
}

void SharkPlay(int turn){
    CopyFish1(copies);
    MoveFishes();
    PrintMap();
    MoveShark(turn);
    // PrintMap();
    SmellDisappear(turn);

    CopyFish2();
    PrintMap();
}

/*
5 2
4 3 5
1 3 5
2 4 2
2 1 6
3 4 4
4 2

5 1
4 3 5
1 3 5
2 4 2
2 1 6
3 4 4
4 2
*/
int main(){

    cin>>fish_n>>shark_play;
    int y, x, dir;
    for(int i=0;i<fish_n;i++){
        cin>>y>>x>>dir;
        map[y][x].fishes.push_back({y,x,8-dir});
    }
    cin>>shark_y>>shark_x;
    // PrintMap();
    for(int i=0;i<shark_play;i++){
        SharkPlay(i);
    }
    // PrintMap();
    vector<Fish> remain;
    CopyFish1(remain);
    cout<<remain.size()<<"\n";

}