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
//		���� ����Ʈ���� ���� 
		long long a=cost[cur]*Distance;
//		���� ����Ʈ������ ������ ���� ������, ���� ����Ʈ���� ���� 
		long long b=cost[cur]*road[i] + cost[i+1]*(Distance-road[i]);
//		���� ����Ʈ���� �����ϴ°� ���� ����Ʈ���� �����ϴ°ͺ��� ��θ� ���� �������� ������ �����ڸ� �����ϰ�  ���� ����Ʈ���� �Ǵ� 
		if(a>b){
//			cout<<"a>b ";
			ans+=cost[cur]*road[i];
			Distance-=road[i];
			cur=i+1;
//		���� ����Ʈ���� �����ϴ°� �� �θ� 
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
