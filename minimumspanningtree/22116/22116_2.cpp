#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int arr[1001][1001];
int dist[1001][1001];
int n;
long long int INF,ans=0;

priority_queue <pair <long long int, pair<int,int>>, vector<pair<long long int, pair<int,int>>>,
greater <pair <long long int, pair<int,int>>>> pq;













void dijkstra(){
	while(!pq.empty()){
		long long int curcost=pq.top().first;
		int curx=pq.top().second.first;
		int cury=pq.top().second.second;
		pq.pop();
		if(dist[curx][cury]!=INF) continue;
		dist[curx][cury]=curcost;
		ans=max(ans,curcost);
		if(curx==n-1&&cury==n-1) break;
		for(int i=0;i<4;i++){
			int nx=curx+dx[i];
			int ny=cury+dy[i];
			if(nx<0||ny<0||nx>=n||ny>=n) continue;
			if(dist[nx][ny]==INF){
				pq.push(make_pair(abs(arr[nx][ny]-arr[curx][cury]),make_pair(nx,ny)));
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	if(n==1){
		cout<<0<<"\n";
		return 0;
	}
	pq.push(make_pair(abs(arr[0][0]-arr[0][1]),make_pair(0,1)));
	pq.push(make_pair(abs(arr[0][0]-arr[1][0]),make_pair(1,0)));
	memset(dist,127,sizeof(dist));
//	cout<<INF;
//	cout<<sizeof(dist)<<" ";
	INF=dist[0][0];
	dist[0][0]=0;
	dijkstra();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<dist[i][j]<<" ";
		cout<<"\n";
	}
//	cout<<ans<<"\n";
}
