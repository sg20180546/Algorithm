#include <iostream>
using namespace std;

long long Distance=0;
int N;
long long road[100001];
long long cost[100002];
long long ans=0;

//distance()
void greedy(){
	int cur=0;
	for(int i=0;i<N-1;i++){
//		cout<<Distance<<" ";
//		현재 포인트에서 완충 
		long long a=cost[cur]*Distance;
//		현재 포인트에서는 다음거 갈꺼 까지만, 다음 포인트에서 완충 
		long long b=cost[cur]*road[i] + cost[i+1]*(Distance-road[i]);
//		현재 포인트에서 완충하는게 다음 포인트에서 완충하는것보다 비싸면 현재 지점에서 다음꺼 갈꺼자만 충전하고  다음 포인트에서 판단 
		if(a>b){
//			cout<<"a>b ";
			ans+=cost[cur]*road[i];
			Distance-=road[i];
			cur=i+1;
//		현재 포인트에서 충전하는게 더 싸면 
		}else{
			ans+=cost[cur]*road[i];
			Distance-=road[i];
		}
//		cout<<ans<<" ";
	}
	
}

int main(){
	
	cin>>N;
	
	for(int i=0;i<N-1;i++){
		long long dis;
		cin>>dis;
		Distance+=dis;
		road[i]=dis;
	}
	for(int i=0;i<N;i++){
		long long c;
		cin>>c;
		cost[i]=c;
	}
	greedy();
	cout<<ans;
	
	return 0;
}
