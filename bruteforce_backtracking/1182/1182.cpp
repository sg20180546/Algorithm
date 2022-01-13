#include <iostream>

using namespace std;

int num[21];
bool check[21];
int N,S;
int ans=0;
int h=0;
void dfs(int idx){
	h++;
	int cnt=0;
//	if(idx==N) return;
	
	for(int i=0;i<N;i++){
		if(check[i]){
			cnt+=num[i];
		}
	}
	if(cnt==S){
		ans++;
	}
//	cout<<cnt<<"\n";
	for(int j=idx+1;j<N;j++){
		check[j]=true;
		dfs(j);
		check[j]=false;
	}
}

int main(){
	cin>>N>>S;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	
	for(int i=0;i<N;i++){
		check[i]=true;
		dfs(i);
		check[i]=false;
	}
//	cout<<h;
	cout<<ans;
}
