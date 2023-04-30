#include <iostream>
#include <cstring>
using namespace std;
int N,L;
int r_map[101][101];
int c_map[101][101];
/*
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2

6 2
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
*/
int Pass(int y,int map[][101]){
    // int road[101];
    // memcpy(road,map[i])

    int* road=map[y];
    bool road_slope[101];
    memset(road_slope,false,N);

    int h=road[0];
    int cur=0;
    for(int i=1;i<N;i++){
        if(road[i]-h>1 || road[i]-h<-1 ){
            return 0;
        }
        if(road[i]-h==1){
            for(int j=i-1;j>=i-L;j--){
                if(j<0){
                    return 0;
                }
                if(road[j]!=h){
                    return 0;
                }
                if(road_slope[j]==true){
                    return 0;
                }
            }
            for(int j=i-1;j>=i-L;j--){
                road_slope[j]=true;
            }
        }
        // down
        if(road[i]-h==-1){
            for(int j=i+1;j<i+L;j++){
                if(j>=N){
                    return 0;
                }
                if(road[j]!=road[i]){
                    return 0;
                }
            }
            for(int j=i;j<i+L;j++){
                road_slope[j]=true;
            }
        }

        h=road[i];
    }
    return 1;
}


int main(){
    int ans=0;
    cin>>N>>L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>r_map[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            c_map[i][j]=r_map[j][i];
        }
    }

    for(int i=0;i<N;i++){
        ans+=Pass(i,r_map);
        ans+=Pass(i,c_map);
    }
    cout<<ans<<"\n";
    return 0;   
}
