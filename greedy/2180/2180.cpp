#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector <pair <int,int>> vec;

long long sec=0;

bool cmp(pair<int,int> pa,pair<int,int>pb){
	int a1=pa.first;
	int a2=pa.second;
	int b1=pb.first;
	int b2=pb.second;
// a 계수가 0이면 바꿔준다 
	if(a1==0) return false;
//	b 계수가 0이면 그대로 
	if(b1==0) return true;
	
	return (a2*b1<a1*b2);
}

int main(){
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		vec.push_back({a,b});
	}
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i=0;i<n;i++){
		sec+=vec[i].second+sec*vec[i].first;
		sec%=40000;
	}
	cout<<sec%40000;

	
	return 0;
}
