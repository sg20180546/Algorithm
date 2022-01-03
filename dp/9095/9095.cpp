#include <iostream>
using namespace std;
int dp[11];



int main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4;i<11;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
}
