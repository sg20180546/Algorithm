#include <iostream>
#include <cstring>
using namespace std;
int R,C;
string ans;
long long map[1001][1001];
bool visit[1001][1001];
long long MIN=999999;

int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int LDUR[]={'L','D','U','R'};
pair <int,int> minindex;


void dfs(int x,int y){
	if(x==C-1&&y==R-1) return;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<0||ny<0||nx>=C||ny>=R||visit[ny][nx]) continue;
		
		ans.push_back(LDUR[i]);
		visit[ny][nx]=true;
		dfs(nx,ny);
		if(ans.size()==R*C-2) return;
		ans.pop_back();
		visit[ny][nx]=false;
	}
}
void greedy(){
	bool state=true;
	bool state2=true;
	if(R%2==1){
		for(int i=1;i<R;i++){
			if(state){
				for(int j=1;j<C;j++) ans.push_back('R');
				state=false;
			}else{
				for(int j=1;j<C;j++) ans.push_back('L');
				state=true;
			}
			
			ans.push_back('D');
		}
		for(int j=1;j<C;j++) ans.push_back('R');
	}
	
	else if(R%2==0&&C%2==1){
		for(int i=1;i<C;i++){
			if(state){
				for(int j=1;j<R;j++) ans.push_back('D');
				state=false;
			}else{
				for(int j=1;j<R;j++) ans.push_back('U');
				state=true;
			}
			ans.push_back('R');
		}
		
		for(int j=1;j<R;j++) ans.push_back('D');
	}
	
	
	else if((R%2==0)&&(C%2==0)){
		dfs(0,0);
	}
}



int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			long long a;
			cin>>a;
			map[i][j]=a;
			
			if( (i%2==1&&j%2==0) || (i%2==0&&j%2==1)){
				if(a<MIN){
					MIN=a;
					minindex.first=i;
					minindex.second=j;
				}
		}
	}
	}

	visit[0][0]=true;
	visit[minindex.first][minindex.second]=true;
	greedy();
	cout<<ans;
	
}

