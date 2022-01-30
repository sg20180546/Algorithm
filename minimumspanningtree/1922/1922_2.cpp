#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <vector<int>> vec;
int N,M,ans=0;

bool cmp(vector<int> a, vector<int> b){
	if(a[2]<b[2]) return true;
	return false;
}
bool connected[1001];

bool check(){
	for(int i=1;i<=N;i++){
		if(!connected[i]) return false;
	}
	
	return true;
}
void sol(){
	
	while(1){
		for(int i=0;i<M;i++){
			if(!connected[vec[i][0]]&&!connected[vec[i][1]]) continue;
			if(connected[ vec[i][0]] && connected[vec[i][1]] ) continue;
			
			if(connected[vec[i][0]]&&!connected[vec[i][1]]){
				ans+=vec[i][2];
				connected[vec[i][1]]=true;
				break;
			}
			else if(!connected[vec[i][0]]&&connected[vec[i][1]]){
				ans+=vec[i][2];
				connected[vec[i][0]]=true;
				break;
			}
		}
		
		if(check()){
			break;
		}
	}	
}

int main(){
	int a,b,c;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		vector<int> v;
		cin>>a>>b>>c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		vec.push_back(v);
	}
	sort(vec.begin(),vec.end(),cmp);
//	cout<<"\n";
//	for(int i=0;i<M;i++){
//		cout<<vec[i][0]<<" "<<vec[i][1]<<" "<<vec[i][2]<<"\n";
//	}
	connected[vec[0][0]]=true;
	connected[vec[0][1]]=true;
	ans+=vec[0][2];
	sol();
	
	cout<<ans;
}
