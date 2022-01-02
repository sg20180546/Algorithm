#include <iostream>
#include <vector>

using namespace std;
vector <vector<int> > vec(13);

int main(){
	
	int a,b;
	for(int i=0;i<12;i++){
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
//	int sum=0;
	int ans;
	for(int i=1;i<13;i++){
		int sum=0;
		if(vec[i].size()==3){
			for(int j=0;j<3;j++) sum+=vec[vec[i][j]].size();
		}
		if(sum==6) ans=i;
	}
	
	cout<<ans;
	
}
