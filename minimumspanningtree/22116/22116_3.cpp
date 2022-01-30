#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
#include <cmath>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int map[1001][1001];
int curve[1001][1001];
int N,INF;
int ans=0;
priority_queue <pair <int,pair<int,int>>, vector<pair<int, pair<int,int>>>,
greater <pair <int, pair<int,int>>>> pq;


void dijkstra(){
	while(!pq.empty()){
		int cost=pq.top().first;
		int y=pq.top().second.first;
		int x=pq.top().second.second;
		pq.pop();
		if(curve[y][x]!=INF) continue;
		curve[y][x]=cost;
		ans=max(cost,ans);
		if(y==N-1&&x==N-1) break;
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||ny<0||nx>=N||ny>=N||curve[ny][nx]!=INF) continue;
			pq.push(make_pair(abs(map[y][x]-map[ny][nx]),make_pair(ny,nx) ));	
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin>>map[i][j];
	}
	if(N==1){
		cout<<0;
		return 0;
	}
	memset(curve,127,sizeof(curve));
	INF=curve[0][0];
//	cout<<INF;
	curve[0][0]=0;
	pq.push(make_pair(abs(map[0][0]-map[0][1]),make_pair(0,1)));
	pq.push(make_pair(abs(map[0][0]-map[1][0]),make_pair(1,0)));
	dijkstra();
	cout<<ans;
}
