#include <iostream>
#include <algorithm>
using namespace std;

int map[1001];
int dp[1001];
int N,num,index;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		map[i]=num;
		dp[i]=1;
	}
//	cout<<"\n";
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(dp[i]>=dp[j]){
				if(map[i]<map[j]){
					dp[j]=dp[i]+1;
				}
			}
		}
//		for(int i=0;i<N;i++) cout<<dp[i]<<" ";
//		cout<<"\n";
	}
//	for(int i=0;i<N;i++) cout<<dp[i]<<" ";
	cout<<*max_element(dp,dp+N);
}
