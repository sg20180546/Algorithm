#include <iostream>
#include <vector>
using namespace std;
bool friends[30001][30001];
vector <int> fvec[30001];
int candy[30001];
int N,M,K,ans=0;

void sol(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(friends[i][j]){
				for(int k=1;k<=N;k++){
					if(friends[j][k]&&!friends[i][k]){
						friends[i][k]=true;
						fvec[i].push_back(k);
					}
				}
			}
		}
	}
}

int getcandy(int idx){
	bool visit[N];
	int cnt=0;
	int ret=0;
	for(int i=idx;i<=N;i++){
		if(cnt+fvec[i].size()>=K) continue;
		if(visit[i]) continue;
		for(int j=0;j<fvec[i].size();j++){
			ret+=candy[fvec[i][j]];
			visit[fvec[i][j]]=true;
		}
		cnt+=fvec[i].size();
	}
	return ret;
}


int main(){
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++){
		cin>>candy[i];
	}
	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		fvec[a].push_back(b);
		fvec[b].push_back(a);
		friends[a][b]=true;
		friends[b][a]=true;
	}
	sol();
//	cout<<"\n";
//	for(int i=1;i<=N;i++){
//		for(int j=0;j<fvec[i].size();j++) cout<<fvec[i][j]<<" ";
//		cout<<"\n";
//	}

	for(int i=1;i<=N;i++){
		ans=max(getcandy(i),ans);
	}
//	cout<<ans;
}
