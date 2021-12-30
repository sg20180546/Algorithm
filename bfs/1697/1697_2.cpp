#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,K,ans;
bool visit[100001];
queue <pair<int,int>> q;

bool valid(int x){
	if(x<0||x>100001||visit[x]) return false;
	return true;
}

void bfs(){
	q.push({N,0});
	visit[N]=true;
	while(!q.empty()){
		int cur=q.front().first;
		int sec=q.front().second;
		q.pop();
		if(cur==K){
			ans=sec;	
			break;
		} 
		if(valid(cur*2)){
			q.push({cur*2,sec+1});
			visit[cur*2]=true;
		}
		if(valid(cur+1)){
			q.push({cur+1,sec+1});
			visit[cur+1]=true;
		}
		if(valid(cur-1)){
			q.push({cur-1,sec+1});
			visit[cur-1]=true;
		}
	}
}

int main(){
	cin>>N>>K;
	bfs();
	cout<<ans;
	
	return 0;
}
