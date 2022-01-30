#include <iostream>
#include <cmath>
using namespace std;

bool player[21];

int stats[21][21];

int N,ans=1<<31-1;

void dfs(int pn,int idx){
	if(pn==N/2){
		int start=0,link=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(player[i]&&player[j]) start+=stats[i][j];
				if(!player[i]&&!player[j]) link+=stats[i][j];
			}
		}
		ans=min(abs(start-link),ans);
		return;
	}
	
	for(int i=idx;i<N;i++){
		player[i]=true;
		dfs(pn+1,i+1);
		player[i]=false;
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>stats[i][j];
		}
	}
	dfs(0,1);
	cout<<ans;
}
