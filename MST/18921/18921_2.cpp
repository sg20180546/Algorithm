#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,ans;
vector <pair <int,pair<int,int>> >  vec;
vector <int> graph[100000];
bool cmp( pair <int,pair <int,int>> a, pair<int,pair<int,int>> b ){
	if(a.first<b.first) return true;
	return false;
}

int unconncect(int a){
	
}

void sol(){
	for(int i=0;i<vec.size();i++){
		for(int j=i;j<N-1;j++){
			
		}
	}
}


int main(){
	int a,b,c;
	cin>>N;
	for (int i=1;i<N;i++){
		cin>>a>>b>>c;
		vec.push_back(make_pair(c,make_pair(a,b)));
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<N-1;i++){
		cout<<vec[i].first<<" ";
	}
	return 0;
}
