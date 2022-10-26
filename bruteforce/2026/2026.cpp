#include <iostream>
#include <vector>
using namespace std;
bool friends[901][901];
int K,N,F;

vector <int> gopicnic;
bool possible=false;
bool check(int person){
	
	for(int i=0;i<gopicnic.size();i++){
		if(!friends[gopicnic[i]][person]){
			return false;
		}
	}
	return true;
}


void dfs(int idx){
	if(gopicnic.size()==K){
		possible=true;
		return;
	}
	for(int i=idx;i<=N;i++){
		if(check(i)){
			gopicnic.push_back(i);
			dfs(i);
			if(possible) return;
			gopicnic.pop_back();
		}
	}
}

int main(){
	cin>>K>>N>>F;
	int a,b;
	for(int i=0;i<F;i++){
		cin>>a>>b;
		friends[a][b]=true;
		friends[b][a]=true;
	}
	dfs(1);

	if(possible){
		for(int i=0;i<gopicnic.size();i++){
			cout<<gopicnic[i]<<"\n";
		}
	}else{
		cout<<-1;
	}
}
