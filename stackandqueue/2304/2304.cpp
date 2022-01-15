#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> vec;
stack <pair<int,int>> s;
stack <pair<int,int>> roof;
int N,ans=0;
bool cmp(pair<int,int> a,pair<int,int>b){
	if(a.first<b.first) return true;
	return false;
}

void calculate(){
	pair<int,int> block=s.top();
	s.pop();
	roof.push(block);
	int maxheight=block.second;
	
	while(!s.empty()){
		block=s.top();
		s.pop();
		if(block.second>=maxheight){
			while(roof.top().second<maxheight){
				roof.pop();
			}
			maxheight=block.second;
			roof.push(block);
		}else{
			if(roof.top().second<block.second)
			while(roof.top().second<=block.second){
				roof.pop();
			}
			roof.push(block);
		}
//		cout<<"hello";
	}
	
//	cout<<roof.size();
	while(roof.size()>1){
		int width;
		block=roof.top();
		roof.pop();

		if(roof.top().second>block.second){
			width=roof.top().first-block.first;
			ans+=width*block.second;
		}else{
			width=roof.top().first-block.first-1;
			ans+=block.second + width*roof.top().second;
		}
//		cout<<roof.top().first<<" ";
	}
	ans+=roof.top().second;
//	ans+=roof.top().second*(roof.top().first-block.second);
}

int main(){
	int a,b;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		vec.push_back({a,b});
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<N;i++){
//		cout<<vec[i].first<<" ";
		s.push(vec[i]);
	} 
	calculate();
	cout<<ans;
}
