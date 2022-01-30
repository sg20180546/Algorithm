#include <iostream>
#include <vector>

using namespace std;
vector <pair <int,int>> vec[1001];
bool connected[1001];
int N,M,ans=1<<31-1;

void dfs(int pos,int cost,int size){
	if(size==N){
//		cout<<cost<<" ";
		ans=min(ans,cost);
		return;
	}
	
	for(int i=0;i<vec[pos].size();i++){
		if(connected[vec[pos][i].first]) continue;
		connected[vec[pos][i].first]=true;
		dfs(vec[pos][i].first, cost+vec[pos][i].second, size+1);
		connected[vec[pos][i].first]=false;
	}
	
}

int main(){
	int a,b,c;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}
	connected[1]=true;
	for(int i=0;i<vec[1].size();i++){
		connected[vec[1][i].first]=true;
		dfs(vec[1][i].first , vec[1][i].second , 2);
		connected[vec[1][i].first]=false;
	}
	cout<<ans;
}
