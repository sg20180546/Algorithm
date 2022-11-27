#include <iostream>
// #include <string>
// #include <stdlib.h>
#include <memory.h>
using namespace std;
// https://boomrabbit.tistory.com/126

int n;
int dp[1000][1000];
int sosu[999999];

int get_sosu(int x, int y){
    int ty=y;
    while(ty>0){
        // printf("ty : %d\n",ty);
        // printf("x : %d\n",x);
        ty/=10;
        x*=10;
    }
    printf("%d %d\n",x,y);
    x+=y;
    if(sosu[x]) return 0;
    return 1;
}

int f(int x,int y){
    if(x<1||y<1){
        return 0;
    }
    int &ret= dp[x][y];
    if(ret!=-1) return ret;

    ret=0;
    ret=max(ret,max(f(x-1,y),f(x,y-1)));
    ret+=get_sosu(x,y);
    return ret;
}

int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));

    /*
        2 - 4 6 8 10 12
        3 - 6 9 12
        4 - 4 8 12 16
        5 - 10 15 20
    */
    for(int i=2;i*i<=1000000;i++){
        for(int j=i+i;j<=1000000;j+=i){
            sosu[j]=1;
        }
    }
    dp[1][1]=0;
    // // cout<<f(n,n);
    // cout<<get_sosu(332,134)<<"\n";
    return 0;
}