#include <iostream>
#define INF 9999999
#include <queue>
using namespace std;

int N,K;
bool visit[1001][1001];
int map[1001][1001];
int dis[1001][1001];

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

typedef struct{
	int x;
	int y;
	int distance;
} element;
queue <element> q;

void bfs(int x,int y){
	while(!q.empty()){
		element e=q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=e.x+dx[i];
			int ny=e.y+dy[i];
			if(nx<0||ny<0||nx>=K||ny>=N||visit[ny][nx]||map[ny][nx]==0) continue;
			
			visit[ny][nx]=true;
			dis[ny][nx]=dis[e.y][e.x]+1;
			
			element e2;
			e2.x=nx;
			e2.y=ny;
			e2.distance=dis[ny][nx];
			
			q.push(e2);
		}
	}
}


int main(void){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	int a,startx,starty;
	cin>>N>>K;

	
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			cin>>a;
			map[i][j]=a;
			if(a==2){
				starty=i;
				startx=j;
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			dis[i][j]=0;
			if(map[i][j]==0){
				dis[i][j]=0;
			}else dis[i][j]=-1;
		}
	}
	
	dis[starty][startx]=0;
	visit[starty][startx]=true;
	element e;
	e.x=startx; e.y=starty; e.distance=0;
	q.push(e);
	
	bfs(startx,starty);

	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
