#include <iostream>
using namespace std;
int value[101];
int dp[10001];
int N,goal;

int main(){
    cin>>N>>goal;
    for(int i=1;i<=N;i++){
        cin>>value[i];
    }
    dp[0]=1;
    for(int i=1;i<=N;i++){
        for(int j=value[i];j<=goal;j++){
            dp[j]+=dp[j-value[i]];
        }
    }

    cout<<dp[goal]<<"\n";
}