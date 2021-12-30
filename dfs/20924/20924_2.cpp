#include <iostream>

#include <vector>
using namespace std;
const int MAXN = 2e5+5;
int N,R;
vector< vector<pair<int,int>> > G(MAXN);

int children[MAXN];
int depth[MAXN];
int giga_node,giga_parent;

void get_depth(int cur,int par,int d){
	depth[cur]=d;
	for(pair<int,int> p : G[cur]){
		int v=p.first;
		int w=p.second;
		if(v==par) continue;
		get_depth(v,cur,d+w);
	}
	return;
}

void get_children(int cur,int par){
	for(pair<int,int> p : G[cur]){
		int v=p.first;
		if(v==par) continue;
		children[cur]++;
	}
	if(children[cur]>1){
		giga_node=cur;
		giga_parent=par;
	}
	
	for(pair<int,int>p :G[cur]){
		int v= p.first;
		if(v==par) continue;
		if(giga_node) return;
		
		get_children(v,cur);
	}
	return;
}

int dfs(int cur,int par){
	int ret=0;
	for(pair<int,int> p:G[cur]){
		int v=p.first;
		int w=p.second;
		if(v==par) continue;
		ret=max(ret,dfs(v,cur)+w);
	}
	return ret;
}

int main(){
	cin>>N>>R;
	for(int i=1;i<N;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v].emplace_back(u,w);
	}
	get_depth(R,0,0);
	get_children(R,0);
	if(giga_node==0){
		for(int i=1;i<=N;i++) if(children[i]==0) giga_node=i;
		cout<<depth[giga_node]<<" "<<0<<"\n";
		return 0;
	}
	cout<<depth[giga_node]<<" "<<dfs(giga_node,giga_parent)<<"\n";
//	for(int i=0;i<13;i++){
//		cout<<children[i]<<" ";
//	}
	return 0;
}
