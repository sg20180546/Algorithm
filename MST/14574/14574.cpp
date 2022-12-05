#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
typedef int ui;

int N;
ui P,C;
long long total=0;

pair<ui,ui> map[1001]; // P, C


// rating, i,j
priority_queue <pair <ui,pair <int,int>>, vector<pair<ui,pair<int,int> > >, less <pair <ui,pair <int,int>> >> pq;

int parent[1001];
vector <int> ans[1001];
int get_parent(int x){
	if(x==parent[x]) return x;
	else return parent[x]=get_parent(parent[x]);
}
void union_parent(int x, int y){
	x=get_parent(x);
	y=get_parent(y);
	parent[x]=y;
}
void sol(){
	while(!pq.empty()){
		pair<ui,pair<int,int>> t=pq.top();
		pq.pop();
		if(get_parent(t.second.first)==get_parent(t.second.second)) continue;
//		cout<<t.first<<"\n";
		total+=t.first;
		union_parent(t.second.first,t.second.second);
		ans[t.second.first].push_back(t.second.second);
		ans[t.second.second].push_back(t.second.first);
	}
}
void print(int win,int lose){
	for(int i=0;i<ans[win].size();i++){
		if(ans[win][i]!=lose) print(ans[win][i],win);
	}
	
	if(lose) cout<<lose<<" "<<win<<endl;
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>P>>C;
		map[i]={P,C};
	}
	for(int i=1;i<=N;i++) parent[i]=i;
	for(int i=1;i<N;i++){
		for(int j=i+1;j<=N;j++){
			ui rating=(map[i].second+map[j].second)/abs(map[i].first-map[j].first);
			pq.push({rating,{i,j} });
		}
	}
	sol();
	for(int i=1;i<=N;i++) cout<<parent[i]<<" ";
//	cout<<total<<"\n";
//	print(1,0);
	return 0;
}
