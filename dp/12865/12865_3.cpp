#include <iostream>
using namespace std;

int V[101];
int W[101];
int N,K;
int dp[101][100001];

int main(){
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>W[i]>>V[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(j-W[i]>=0){
                dp[i][j]=max(dp[i-1][j],dp[i][j-W[i]]+V[i] );
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}