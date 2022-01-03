#include <iostream>
#include <vector>
using namespace std;
int dp[110][110];
int N,M;

vector <bool> restday(110);

int sol(int day,int coupon,int price){
	if(day>N) return price;
	if(dp[day][coupon]) return dp[day][coupon]+price;
	if(restday[day]) return sol(day+1,coupon,price);
	
	int answer=999999;
	answer=min(answer,sol(day+1,coupon,price+10000));
	answer=min(answer,sol(day+3,coupon+1,price+25000));
	answer=min(answer,sol(day+5,coupon+2,price+37000));
	if(coupon>=3) answer=min(answer,sol(day+1,coupon-3,price));
	
	dp[day][coupon]=answer-price;
	cout<<day<<" "<<coupon<<" "<<price<<"\n"; 
	return answer;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int r;
		cin>>r;
		restday[r]=true;
	}
	sol(1,0,0);
//	cout<<sol(1,0,0);
//	for(int i=1;i<=N;i++){
//		for(int j=0;j<10;j++) printf("%6d ",dp[i][j]);
//		cout<<"\n";
//	}
}
