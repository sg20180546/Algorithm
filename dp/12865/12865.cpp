#include <iostream>
using namespace std;

int N,K;
int W[100001];
int V[101];

int dp[101][100001];
/*
4 7
6 13
4 8
3 6
5 12

    0   1   2   3   4   5   6   7
0   0   0   0   0   0   0   0   0
1   0   0   0   0   0   0   13  13
2   0   0   0   0   8   8   13  13
3   0   0   0   6   8   8   13  8+6   
4   0   0   0   6   8   12  13  14
*/
int main(){
    cin>>N>>K;

    for( int i=1;i<=N;i++){
        cin>>W[i]>>V[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(j-W[i]>=0){
                dp[i][j]=max(dp[i-1][j-W[i]]+V[i] ,dp[i-1][j] );
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[N][K];
}