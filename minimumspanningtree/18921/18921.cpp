#include <iostream>
#include <cstring>

using namespace std;
int INF= 1<<31-1;
int parent[100000];
int mincost[100000];
int treesize[100000];
int ans=0;
int get_parent(int x,int cost){
//	cout<<"h";
	if(x==parent[x]){
		mincost[x]=min(cost,mincost[x]);	
		return x;
	}
	else{
		mincost[x]=INF;
		return parent[x]=get_parent(parent[x],cost);
//		mincost[x]=INF;
	}
}

void union_parent(int x,int y,int cost){
//	cout<<"hello";
	x=get_parent(x,cost);
	y=get_parent(y,cost);
	if(x<y){
		parent[y]=x;
		mincost[x]=min(mincost[y],min(cost,mincost[x]));
		mincost[y]=INF;
	}
	else{
		parent[x]=y;
		mincost[y]=min(mincost[x],min(cost,mincost[y]));
		mincost[x]=INF;
	}
}

int N;

int main(){
//	memset(mincost,127,sizeof(mincost));
	cin>>N;
//	cout<<INF;
	for(int i=1;i<=N;i++){
		parent[i]=i;
		treesize[i]=1;
		mincost[i]=INF;
//		cout<<INF;
	}
	int a,b,c;
	for(int i=1;i<N;i++){
		cin>>a>>b>>c;
		union_parent(a,b,c);
	}
	for(int i=1;i<=N;i++){
		if(parent[i]==i) continue;
		int t=get_parent(i,INF);
		treesize[t]++;
	}
	for(int i=1;i<=N;i++){
		if(parent[i]==i){
			ans=max(ans,mincost[i]*treesize[i]);
		}
	}
	cout<<ans;
}
