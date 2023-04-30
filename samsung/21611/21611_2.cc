#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N,M;
int A[50][50];

vector<int> v;
int d, s;
int sharkX,sharkY;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int ddx[4]={-1,0,1,0};
int ddy[4]={0,1,0,-1};

int score;
bool check(int y,int x){
    return y>=0&&y<N&&x>=0&&x<N;
}
void move(){
    v.clear();
    int distance = 1;
    int nx = sharkX;
    int ny = sharkY;
    d=0;
    int cnt = 0; int maxCnt= N*N-1;
    while(1){
        for(int i=0;i<2;i++){
            for(int j =0 ;j<distance;j++){
                nx += ddx[d];
                ny += ddy[d];
                cnt++;
            }
            if(!check(ny,nx)){
                continue;
            }
            if(A[ny][nx]>0){
                v.push_back(A[ny][nx]);
            }

        }
        if(cnt>=maxCnt){
            break;
        }
        d=(d+1)%4;

    }
}
