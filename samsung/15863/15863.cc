#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
enum{
    VOID,C1,C2,C3,C4,C5,WALL,WATCHED
};
enum {
    EAST,WEST,NORTH,SOUTH
};

int map[10][10];
int N,M;
int walls=0;
int ans=INT32_MAX;

void PrintMap(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

struct Camera{
    Camera * target;
    int cases=0;
    Camera(int c): target(this),cases(c) { }
    void Watch(int i,int y,int x,vector<pair<int,int>>& coverage){
        switch (i)
        {
        case 0:
            target->W0(y,x,coverage);
            break;
        case 1:
            target->W1(y,x,coverage);
            break;
        case 2:
            target->W2(y,x,coverage);
            break;
        case 3:
            target->W3(y,x,coverage);
            break;
        default:
            break;
        }
    }
protected:
    virtual void W0(int y, int x,vector<pair<int,int>>& coverage) { assert(0); }
    virtual void W1(int y, int x,vector<pair<int,int>>& coverage) { assert(0); }
    virtual void W2(int y ,int x,vector<pair<int,int>>& coverage) { assert(0); }
    virtual void W3(int y, int x,vector<pair<int,int>>& coverage) { assert(0); }
    bool Check(int y, int x){
        return y>=0&&y<N&& x>=0 && x<M && map[y][x]!=WALL;
    }
};

struct C1 : public Camera{
    C1() : Camera(4) {}
private:
    //EAST
    void W0(int y, int x,vector<pair<int,int>>& coverage) override{
        for(;Check(y,x);x++){
            if(map[y][x]!=VOID){
                continue;
            }
            map[y][x]=WATCHED;
            coverage.emplace_back(y,x);
        }
    }

    // WEST
    void W1(int y, int x,vector<pair<int,int>>& coverage) override{
        for(;Check(y,x);x--){
            if(map[y][x]!=VOID){
                continue;
            }
            map[y][x]=WATCHED;
            coverage.emplace_back(y,x);
        }
    }
    // NORTH
    void W2(int y, int x,vector<pair<int,int>>& coverage) override{
        for(;Check(y,x);y--){
            if(map[y][x]!=VOID){
                continue;
            }
            map[y][x]=WATCHED;
            coverage.emplace_back(y,x);
        }
    }
    // SOUTH
    void W3(int y,int x,vector<pair<int,int>>& coverage) override{
        for(;Check(y,x);y++){
            if(map[y][x]!=VOID){
                continue;
            }
            map[y][x]=WATCHED;
            coverage.emplace_back(y,x);
        }
    }
};
struct C1 c1;
struct C2 : public Camera{
    C2() : Camera(2) {}
private:
    // VERITCAL
    void W0(int y, int x,vector<pair<int,int>>& coverage) override{
        c1.Watch(WEST,y,x,coverage);
        c1.Watch(EAST,y,x,coverage);
    }
    // HORIZONTAL
    void W1(int y, int x,vector<pair<int,int>>& coverage) override{
        c1.Watch(NORTH,y,x,coverage);
        c1.Watch(SOUTH,y,x,coverage);
    }
};

struct C3 : public Camera{
    C3() : Camera(4) {}
private:
    // NE
    void W0(int y, int x,vector<pair<int,int>>& coverage) override{
        c1.Watch(NORTH,y,x,coverage);
        c1.Watch(EAST,y,x,coverage);
    }
    // SW
    void W1(int y, int x,vector<pair<int,int>>& coverage) override{
        c1.Watch(SOUTH,y,x,coverage);
        c1.Watch(WEST,y,x,coverage);
    }
    // SE
    void W2(int y, int x,vector<pair<int,int>>& coverage) override{
        c1.Watch(SOUTH,y,x,coverage);
        c1.Watch(EAST,y,x,coverage);
    }
    // NW
    void W3(int y,int x,vector<pair<int,int>>& coverage) override{
        c1.Watch(NORTH,y,x,coverage);
        c1.Watch(WEST,y,x,coverage);
    }
};

struct C4 : public Camera{
    C4() :Camera(4) {}
private:
    // EXECPT EAST
    void W0(int y, int x,vector<pair<int,int>>& coverage) override{
        for(int i=EAST;i<4;i++){
            if(i==EAST){
                continue;
            }
            c1.Watch(i,y,x,coverage);
        }
    }
    // EXCEPT WEST
    void W1(int y, int x,vector<pair<int,int>>& coverage) override{
        for(int i=EAST;i<4;i++){
            if(i==WEST){
                continue;
            }
            c1.Watch(i,y,x,coverage);
        }
    }
    // EXECPT SOUTH
    void W2(int y, int x,vector<pair<int,int>>& coverage) override{
        for(int i=EAST;i<4;i++){
            if(i==SOUTH){
                continue;
            }
            c1.Watch(i,y,x,coverage);
        }
    }
    // EXCEPT NORTH
    void W3(int y,int x,vector<pair<int,int>>& coverage) override{
        for(int i=EAST;i<4;i++){
            if(i==NORTH){
                continue;
            }
            c1.Watch(i,y,x,coverage);
        }
    }
};
struct C5 : public Camera{
    C5() : Camera(1) {}
private:
    void W0(int y, int x,vector<pair<int,int>>& coverage) override{
        for(int i=EAST;i<4;i++){
            c1.Watch(i,y,x,coverage);
        }
    }
};

struct C2 c2;
struct C3 c3;
struct C4 c4;
struct C5 c5;
struct Camera cameras[5]={c1,c2,c3,c4,c5};


vector<pair<int,int>> c_pos;

void sol(int idx, int sum){
    int unreached;
    int y;
    int x;
    int ctype;
    int cases;
    vector<pair<int,int>> coverage;
    if(idx==c_pos.size()){
        unreached=N*M-sum-walls-c_pos.size();
        if(ans>unreached){
            ans=unreached;
        }
        return;
    }
    y=c_pos[idx].first;
    x=c_pos[idx].second;
    ctype=map[y][x]-1;
    cases=cameras[ctype].cases;
    for(int j=0;j<cases;j++){
        coverage.clear();
        cameras[ctype].Watch(j,y,x,coverage);
        sol(idx+1,coverage.size()+sum);
        for(auto c : coverage){
            map[c.first][c.second]=VOID;
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==WALL){
                walls++;
                continue;
            }
            if(map[i][j]!=VOID&&map[i][j]!=WALL){
                c_pos.emplace_back(i,j);
            }
        }
    }
    sol(0,0);
    cout<<ans<<"\n";
}