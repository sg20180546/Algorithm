#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
bool map[16][16];
bool test[16][16];
bool ans[16][16];
bool possible;
int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
vector <int> vec;
vector <int> ansvector;
bool check(){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(test[i][j]==true){
				return false;
			}
		}
	}
	return true;
}


void reverse(int y,int x){
	int nx,ny;
	test[y][x]=!test[y][x];
	for(int i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0||ny<0||nx>=M||ny>=N) continue;
		test[ny][nx] =!test[ny][nx];
	}
}

pair <int,int> getxy(int num){
	return {num%M,num/N};
}

 


void dfs(int count,int idx,int ansize){
	if(idx==N*M) return;
	if(count==0){
		pair <int,int> xy;
		for(int i=0;i<ansize;i++){
			xy=getxy(vec[i]);
			reverse(xy.second,xy.first);
		}
		if(check()){
			sort(vec.begin(),vec.end());
			if(!possible){
				for(int i=0;i<ansize;i++) ansvector.push_back(vec[i]);
				possible=true;
				return;
			}
			for(int i=0;i<ansize;i++){
				if(ansvector[i]==vec[i]) continue;
				else if(ansvector[i]<vec[i]) break;
				else if(ansvector[i]>vec[i]) return;
			}
			for(int i=0;i<ansize;i++){
				ansvector[i]=vec[i];
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				test[i][j]=map[i][j];
			}
		}
		return;
	}
	
	for(int i=idx;i<N*M&&count!=0;i++){
		vec.push_back(i);
		dfs(count-1,idx+1,ansize);
		vec.pop_back();
	}
}

int main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>M;
	int a;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>a;
			if(a==1){
				map[i][j]=true;
				test[i][j]=true;
			}
			else{
				map[i][j]=false;
				test[i][j]=false;
			}
		}
	}
	int count;
	for(count=0;count<N*M;count++){
		dfs(count,0,count);
		if(possible) break;
	}

	pair <int,int> xy;
	for(int i=0;i<count;i++){
		xy=getxy(ansvector[i]);
		ans[xy.second][xy.first]=true;
	}
	
	if (possible) for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(ans[i][j]) cout<<1<<" ";
			else cout<<0<<" ";
		}
		cout<<"\n";
	}else cout<<"IMPOSSIBLE";
}
