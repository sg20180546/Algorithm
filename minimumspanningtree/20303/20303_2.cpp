#include <iostream>

using namespace std;

using ll = long long;

int parent[30010];
int dp[3010];
int candy[30010],person[30010];
int get_parent(int x);
void union_parent(int x, int y){
	x=get_parent(x);
	y=get_parent(y);
	if(x<y) parent[y]=x;
	else parent[x]=y;
}

int get_parent(int x){
	if(x==parent[x]) return x;
	return parent[x]=get_parent(parent[x]);
}

int main(){
	int N,M,K;
	int x,y;
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++) parent[i]=i;
	for(int i=1;i<=N;i++){
		cin>>candy[i];
		person[i]=1;
	}
	for(int i=0;i<M;i++){
		cin>>x>>y;
		union_parent(x,y);
	}
	for(int i=1;i<=N;i++){
		if(parent[i]!=i){
			int p=get_parent(i);
			candy[p]+=candy[i];
			person[p]+=person[i];
		}
	}
	for(int i=1;i<=N;i++) cout<<parent[i]<<" ";
		for(int i=1;i<=N;i++){
			if(parent[i]!=i) continue;
			for(int j=K-1;j-person[i]>=0;j--){
				dp[j]=max(dp[j],dp[j-person[i]]+candy[i]);
			}
		}
//	cout<<dp[K-1];
	return 0;
}
