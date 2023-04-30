#include <iostream>
#include <vector>
using namespace std;

int dy[]={-1,-1, 0, 1, 1, 1, 0,-1};
int dx[]={ 0, 1, 1, 1, 0,-1,-1,-1};
int N,M,K;

struct FireBall{
    int mass;
    int dir;
    int v;
};

vector<FireBall> map[51][51];

vector<FireBall> map_tmp[51][51];

void Move(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map_tmp[i][j].clear();
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(auto fb : map[i][j]){
                int y=i;int x=j;
                int ny,nx;
                for(int v=0;v<fb.v;v++){
                    ny=y+dy[fb.dir];
                    nx=x+dx[fb.dir];
                    if(ny>=N){
                        ny=0;
                    }
                    if(ny<0){
                        ny=N-1;
                    }
                    if(nx>=N){
                        nx=0;
                    }
                    if(nx<0){
                        nx=N-1;
                    }
                    y=ny; x=nx;
                }
                map_tmp[y][x].push_back(fb);
            }
            map[i][j].clear();
        }
    }
}

void MergeAndSplit(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int n =map_tmp[i][j].size();
            if(n>1){
                bool odd=true;
                bool even=true;
                int mass_sum=0;
                int vel_sum=0;
                for(auto fb: map_tmp[i][j]){
                    mass_sum+=fb.mass;
                    vel_sum+=fb.v;
                    if(fb.dir%2==0){
                        odd=false;
                    }else{
                        even=false;
                    }
                }
                
                int d = even||odd ? 0 : 1;
                int new_mass=mass_sum/5;
                int new_vel=vel_sum/n;
                if(new_mass==0){
                    continue;
                }
                for(;d<8;d+=2){
                    map[i][j].push_back({new_mass,d,new_vel});
                }
            }else if(n==1){
                map[i][j].push_back(map_tmp[i][j][0]);
            }
        }
    }
}

int Answer(){
    int ret= 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(auto fb : map[i][j]){
                ret+=fb.mass;
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d %d %d",&N,&M,&K);
    while(M--){
        FireBall fb;
        int y,x;
        scanf("%d %d %d %d %d",&y,&x,&fb.mass,&fb.v,&fb.dir);
        map[y-1][x-1].push_back(fb);
    }

    while(K--){
        Move();
        MergeAndSplit();
    }
    printf("%d\n",Answer());
}