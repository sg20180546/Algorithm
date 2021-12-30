#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visit[100001];
int result,N,K;
queue <pair <int,int >> q;


bool valid(int n){
	if(n>100000||n<0||visit[n]){
		return false;
	}
	return true;
}

void bfs(){
	while(!q.empty()){
		int data=q.front().first;
		int sec=q.front().second;
		q.pop();
		if(data==K){
			result=sec;
			break;
		}
		if(valid(data-1)){
			visit[data-1]=true;
			q.push({data-1,sec+1});
		}
		
		if(valid(data+1)){
			visit[data+1]=true;
			q.push({data+1,sec+1});
		}
		
		if(valid(data*2) ){
			visit[data*2]=true;
			q.push( {data*2,sec+1} );
		}
	}
}


int main(){
	cin>>N>>K;
	
	q.push({N,0});
	visit[N]=true;
	
	bfs();
	
	cout<<result;
	return 0;
}



