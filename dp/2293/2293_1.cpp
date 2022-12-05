#include <iostream>

using namespace std;

int value[101];

int dp[10001];
int N,goal;

/*
3 10
1 2 5
------
dp

0   1   
1   1
2   1   2
3   1   2
4   1   3
5   1   3   4
6   1   4   5
7   1   4   6
8   1   5   7
9   1   5   8
10  1   6   10

*/
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