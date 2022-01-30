#include <iostream>
#include <algorithm>
#include <vector>
#define N 1001
//#define F second.first
//#define S second.second
using namespace std;
typedef pair<int,pair<int,int>> P;
int n,d[N][2],i,j,g[N];

long long s;
vector <P> v;
vector <int> w[N];
int f(int x){
	return x==g[x] ? x: g[x]=f(g[x]);
}
void u(int x,int y){
	g[f(x)]=f(y);
}
// 1 0
// 3 1
void r(int p, int u){
	for(int i=0;i<w[p].size();i++){
		if(w[p][i]!=u) r(w[p][i],p);
	}
//	for(int x:w[p]) if(x!=u) r(x,p);
	if(u) cout<<u<<" "<<p<<endl;
//	cout<<u<<" "<<p<<endl;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		g[i]=i;
		cin>>d[i][0]>>d[i][1];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++) v.push_back({ (d[i][1]+ d[j][1]) /abs(d[i][0]-d[j][0]),{i,j}});
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(P x:v){
		if(f(x.second.first)!=f(x.second.second)){
			s+=x.first;
//			cout<<x.first<<"\n";
			w[x.second.first].push_back(x.second.second);
			w[x.second.second].push_back(x.second.first);
			u(x.second.first,x.second.second);
		}
	}
	cout<<s<<endl;
	r(1,0);
}
