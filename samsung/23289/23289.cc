#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
enum {
 RIGHT,LEFT,UP,DOWN,NW,SW,SE,NE
};

int dy[8]={0,0,-1,1, -1, 1,1,-1};
int dx[8]={1,-1,0,0, -1,-1,1, 1};

struct Cell{
 int temperture = 0;
 bool wall[4];
};

struct Heater{
 int y,x,direction;
 void Operate();
};

int R,C,K,W;
int chocolate = 0;
Cell map[21][21];

vector<Heater> heater;
vector<pair<int,int>> target;
enum{ EMPTY,W_R,W_L,W_U,W_D,TARGET};

void Heat();
void Spread();
void Decrease();
bool Test();
void PrintMap();
bool check(int y, int x){
 return y<R&&y>=0&&x>=0&&x<C;
}

int main(){
 cin>>R>>C>>K;
 for(int i=0;i<R;i++){
 for(int j=0;j<C;j++){
 int type;
 cin>>type;
 switch (type)
 {
 case TARGET:
 target.push_back({i,j});
 break;
 case EMPTY:
 break;
 default:
 heater.push_back({i,j,type-1});
 break;
 } 
 }
 }
 cin>>W;
 for(int i=0;i<W;i++){
 int x,y,t;
 cin>>y>>x>>t;
 y--; x--;
 if(t==0){
 map[y][x].wall[UP]=true;
 map[y-1][x].wall[DOWN]=true;
 }else{
 map[y][x].wall[RIGHT]=true;
 map[y][x+1].wall[LEFT]=true;
 }
 }

 while(chocolate<=100){
    Heat();

    Spread();

    Decrease();
    chocolate++;
    if(Test()){
    break; 
 }
 }
 cout<<chocolate<<"\n";
 return 0; 
}

void Heat(){
 for(auto h : heater){
 h.Operate();
 }
}

struct CellTemp{
 int y,x;
 int temp;
 int dir;
};

void Heater::Operate(){
 int map_tmp[R][C];
 memset(map_tmp,0,sizeof(map_tmp));
 queue<CellTemp> q;
 // check can move
 if(check(y+dy[direction],x+dx[direction])){
 q.push({y+dy[direction],x+dx[direction],5,direction});
 }
 while(!q.empty()){
 CellTemp c_tmp=q.front();
 q.pop();
 if(c_tmp.temp==0){
 continue;
 }
 map_tmp[c_tmp.y][c_tmp.x]=c_tmp.temp;

 int ny = c_tmp.y+dy[c_tmp.dir];
 int nx = c_tmp.x+dx[c_tmp.dir];
 
 if(check(ny,nx) && map[c_tmp.y][c_tmp.x].wall[c_tmp.dir]==false ){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }

 switch (c_tmp.dir)
 {
 case LEFT:
 // NW,SW
 ny = c_tmp.y + dy[NW];
 nx = c_tmp.x + dx[NW];

 if(check(ny,nx)&&map[c_tmp.y-1][c_tmp.x].wall[DOWN]==false&&map[c_tmp.y-1][c_tmp.x].wall[LEFT]==false ){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }

 ny = c_tmp.y+ dy[SW];
 nx = c_tmp.x + dx[SW];
 if(check(ny,nx)&&map[c_tmp.y+1][c_tmp.x].wall[UP]==false&&map[c_tmp.y+1][c_tmp.x].wall[LEFT]==false){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }
 break;
 case RIGHT:
 // NE,SE
 ny = c_tmp.y+dy[NE];
 nx = c_tmp.x+dx[NE];
 if(check(ny,nx)&&map[c_tmp.y-1][c_tmp.x].wall[DOWN]==false&&map[c_tmp.y-1][c_tmp.x].wall[RIGHT]==false){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }

 ny = c_tmp.y+dy[SE];
 nx = c_tmp.x+dx[SE];
 if(check(ny,nx) && map[c_tmp.y+1][c_tmp.x].wall[UP]==false&&map[c_tmp.y+1][c_tmp.x].wall[RIGHT]==false ){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }
 break;
 case UP:
 // NW,NE
 ny=c_tmp.y+dy[NW];
 nx=c_tmp.x+dx[NW];
 if(check(ny,nx)&&map[c_tmp.y][c_tmp.x-1].wall[RIGHT]==false&&map[c_tmp.y][c_tmp.x-1].wall[UP]==false){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }

 ny=c_tmp.y+dy[NE];
 nx=c_tmp.x+dx[NE];
 if(check(ny,nx)&&map[c_tmp.y][c_tmp.x+1].wall[LEFT]==false && map[c_tmp.y][c_tmp.x+1].wall[UP]==false){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }
 break;
 case DOWN:
 // SW,SE
 ny = c_tmp.y+dy[SW];
 nx = c_tmp.x+dx[SW];
 if(check(ny,nx)&&map[c_tmp.y][c_tmp.x-1].wall[RIGHT]==false&&map[c_tmp.y][c_tmp.x-1].wall[DOWN]==false){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }

 ny = c_tmp.y+dy[SE];
 nx = c_tmp.x+dx[SE];
 if(check(ny,nx)&&map[c_tmp.y][c_tmp.x+1].wall[LEFT]==false&&map[c_tmp.y][c_tmp.x+1].wall[DOWN]==false){
 q.push({ny,nx,c_tmp.temp-1,c_tmp.dir});
 }
 break;
 default:
 break;
 }
 }

 for(int i=0;i<R;i++){
 for(int j=0;j<C;j++){
 map[i][j].temperture+=map_tmp[i][j];
 }
 }
}

void PrintMap(){
 for(int i = 0; i < R; i++){
 for(int j = 0 ;j < C ;j++){
 printf("%3d ",map[i][j].temperture);
 }
 printf("\n");
 }
 printf("\n");
}

void Spread(){
 int map_tmp[R][C];
 memset(map_tmp,0,sizeof(map_tmp));
 for(int i=0;i<R;i++){
 for(int j =0 ; j<C;j++){
 for(int k =0;k<4;k++){
 if(map[i][j].wall[k]==true){
 continue;
 }
 int cmp_y=i+dy[k];
 int cmp_x=j+dx[k];
 if(!check(cmp_y,cmp_x)){
    continue;
 }
 int diff=map[i][j].temperture-map[cmp_y][cmp_x].temperture;
 if(diff<=0){
 continue;
 }
 int spread_diff=diff/4;
 map_tmp[i][j]-=spread_diff;
 map_tmp[cmp_y][cmp_x]+=spread_diff;
 }
 }
 }

 for(int i=0;i<R;i++){
 for(int j=0;j<C;j++){
 map[i][j].temperture+=map_tmp[i][j];
 }
 }
}

void Decrease(){
 for(int i = 1 ;i<C-1 ;i++){
 if(map[0][i].temperture>0){
 map[0][i].temperture--;
 }
 if(map[R-1][i].temperture>0){
 map[R-1][i].temperture--;
 }
 }

 for(int j = 1 ; j< R-1;j++){
 if(map[j][0].temperture>0){
 map[j][0].temperture--;
 }
 if(map[j][C-1].temperture>0){
 map[j][C-1].temperture--;
 }
 }
 if(map[0][0].temperture>0){
 map[0][0].temperture--;
 }
 if(map[R-1][C-1].temperture>0){
 map[R-1][C-1].temperture--;
 }
 if(map[R-1][0].temperture>0){
 map[R-1][0].temperture--;
 }
 if(map[0][C-1].temperture>0){
 map[0][C-1].temperture--;
 }
}

bool Test(){
 for( auto t : target){
 if(map[t.first][t.second].temperture<K){
 return false;
 }
 }
 return true;
}