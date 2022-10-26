#include <iostream>
#include <queue>
#include <string>

using namespace std;
int N,M;

queue<std::pair<std::pair<int,int>,int> > q;
int map[1003][1003];
int ans;


int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int ny, int nx){
    return (nx>=0 && ny>=0 && nx<M && ny<N);
}

int bfs(){

    int moved[1003][1003][2];

    moved[0][0][1]=1;
    q.push({{0,0},1});

    while(!q.empty()){
        int y=q.front().first.first;
        int x=q.front().first.second;
        int block=q.front().second;
        q.pop();
        // printf("%d %d %d/ %d\n",y,x,block,moved[y][x][block]);
        if(x==M-1&&y==N-1){
            return moved[y][x][block];
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];


            if(check(ny,nx)==true){
                if(map[ny][nx]==1&&block){
                    moved[ny][nx][block-1] = moved[y][x][block] +1;
                    q.push({{ny,nx},block-1});
                }

                if(map[ny][nx]==0&&moved[ny][nx][block]==0) {
                    moved[ny][nx][block] = moved[y][x][block]+1;
                    q.push({{ny,nx},block});
                }

            }

        }
    }
    return -1;
}


int main(){
    cin.tie(); cout.tie(0);
    ios::sync_with_stdio(false);
    // printf("??");
    string s;
    cin>>N>>M;
    ans=INT32_MAX;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<M;j++){
            if(s[j]=='1'){
                map[i][j]=1;
            }else{
                map[i][j]=0;
            }
        }
    }
    // map[0][0]=1;

    ans=bfs();


    
    // if(ans==INT32_MAX){
    //     ans=-1;
    // }
    cout<<ans<<"\n";


}