#include <iostream>
#include <cmath>

using namespace std;

int stats[21][21];
bool check[22];
int N;
int ans=1<<32-2;


void dfs(int x, int pos){
	if(x==N/2){
		int start,link;
		start=0;
		link=0;
		
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(check[i]==true&&check[j]==true) start+=stats[i][j];
				if(check[i]==false&&check[j]==false) link+=stats[i][j];
			}
		}
		ans=min(ans,abs(start-link));
		return;
	}
	for(int i=pos;i<N;i++){
		check[i]=true;
		dfs(x+1,i+1);
		check[i]=false;
	}
	
}
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) cin>>stats[i][j];
	}
	
	dfs(0,1);
	cout<<ans;
}
