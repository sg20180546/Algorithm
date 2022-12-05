#include <iostream>
#include <memory.h>
using namespace std;
int N;

bool prime[1000001];
int dp[1001][1001];

int check(int a, int b){
    int tmp_b=b;
    while(tmp_b){
        tmp_b/=10;
        a*=10;
    }
    return prime[a+b];
}

int sol(int a, int b){
    if(a<1||b<1){
        return 0;
    }
    if(dp[a][b]!=-1){
        return dp[a][b];
    }
    dp[a][b]=0;
    dp[a][b]=max(sol(a-1,b),sol(a,b-1));
    dp[a][b]+=check(a,b);
    return dp[a][b];
}


int main(){
    cin>>N;
    memset(prime,true,sizeof prime);
    memset(dp,-1,sizeof dp);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<1000001;i++){
        for(int j=i+i;j<1000001;j+=i){
            prime[j]=false;
        }
    }
    dp[1][1]=0;
    // for(int i=0;i<100;i++){
    //     printf("%d %s\n",i, prime[i] ? " sosu " : "no");
    // }
    // cout<<check(33,55);
    cout<<sol(N,N)<<"\n";
}