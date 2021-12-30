#include <iostream>
#include <queue>
using namespace std;
int N,M;

bool visit[31][31];
int d1[31][31];
int d2[31][31];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool ans=true;;
typedef struct{
	int x;
	int y;
	int key;
}element;
queue <element> q;

void bfs(element e){
	q.push(e);
	visit[e.y][e.x]=true;
	d1[e.y][e.x]=d2[e.y][e.x];
	
	while(!q.empty()){
		for(int i=0;i<4;i++){
			
			int nx=q.front().x+dx[i];
			int ny=q.front().y+dy[i];
			
			if(nx<0||ny<0||ny>=N||nx>=M||visit[ny][nx]) continue;
			if(d1[ny][nx]!=e.key) continue;
			
			
			element e2;
			e2.key=e.key;
			e2.x=nx;
			e2.y=ny;
			
			d1[ny][nx]=d2[e.y][e.x];
			visit[ny][nx]=true;
			q.push(e2);
		}
		q.pop();
	}
}

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>d1[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>d2[i][j];
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(d1[i][j]!=d2[i][j]){
				element e;
				e.x=j;
				e.y=i;
				e.key=d1[i][j];
				bfs(e);
				i=N;
				break;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(d1[i][j]!=d2[i][j]){
				ans=false;
			}
		}
	}
	if(ans){
		cout<<"YES";
	}else cout<<"NO";
	
	
	
	return 0;
}
