#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans=0;
int map[502][502];
bool visited[502][502];
int N,M;
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};
// int block[4][4][10]={
//     {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
//     {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}},
//     {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
//     {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,1,0,0}},
//     {{}}
// };

bool check(int y, int x){
    return y>=0&&y<N&&x>=0&&x<M;
}



void DFS(int y, int x, int sum,int n){
    if(n==3){
        ans = max(ans,sum);
        return;
    }
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(check(ny,nx) && visited[ny][nx]==false){
            visited[ny][nx]=true;
            DFS(ny,nx,sum+map[ny][nx],n+1);
            visited[ny][nx]=false;
        }
    }


    
}

void exception_s(int y, int x){
    vector<int> v;
    v.clear();
    int tmp=map[y][x];

    for(int k=0;k<4;k++){
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(check(ny,nx)){
            v.push_back(map[ny][nx]);
        }
    }

    sort(v.begin(),v.end());

    if(v.size()==4){
        v[0]=0;
    }
    for(int k=0;k<v.size();k++){
        // printf("%d ",v[k]);
        tmp+=v[k];
    }
    // printf("\n");

    ans=max(ans,tmp);
}
        


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    



    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=true;
            DFS(i,j,map[i][j],0);
            visited[i][j]=false;
            exception_s(i,j);


        }
    }



    cout<<ans;
    return 0;
}