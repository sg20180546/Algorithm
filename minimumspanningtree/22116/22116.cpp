#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int N,ans=0;
int map[1001][1001];

bool visit[1001][1001];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool complete;
bool sol(int y,int x,int cost){
	if(y==N-1&&x==N-1){
		return true;	
	}
	int nx,ny;
	bool flag=false;
	for(int i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=N||visit[ny][nx]) continue;
		if( abs(map[ny][nx]-map[y][x])>cost) continue;
		visit[ny][nx]=true;
//		cout<<x<<" "<<y<<" "<<cost<<"\n";
		flag|=sol(ny,nx,cost);
		visit[ny][nx]=false;
	}
	return flag;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	visit[0][0]=true;
	int start=0,end=1000000000;
//	cout<<end;
	while(start<=end){
		int mid=(end+start)/2;
		if(sol(0,0,mid)){
			ans=mid;
			end=mid-1;
		}else{
			start=mid+1;
		}
		
	}
	
	cout<<ans;
}
