#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	cin.tie(0);
	int N;
	cin>>N;
	int dp[N+1][N+1];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++) cin>>dp[i][j];
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			if(j==0) dp[i][j]+=dp[i-1][j];
			else if(j==i) dp[i][j]+=dp[i-1][j-1];
			else dp[i][j]=dp[i][j]+max(dp[i-1][j-1],dp[i-1][j]); 
		}
	}
	
	cout<<*max_element(dp[N-1],dp[N-1]+N);
	
} 
