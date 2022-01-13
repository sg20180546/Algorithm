#include <iostream>
#include <algorithm>
using namespace std;

int player[21][21];
int team1[10];
int team2[10];
int N;
int ans=1<<32-2;

bool search(int n){
	for(int i=0;i<N;i++){
		if(team1[i]==n) return true;
	}
	return false;
}



void sol(int size){
	
	if(size==N/2){
		int ab1=0,ab2=0;
		for(int i=0;i<size;i++){
			for(int j=i;j<size;j++){
				ab1+=player[team1[i]][team1[j]];
				ab1+=player[team1[j]][team1[i]];
			}
		}
		int j=0;
		for(int i=0;i<N;i++){
			if(!search(i)) team2[j++]=i;
		}
		
		for(int i=0;i<size;i++){
			for(int j=i;j<size;j++){
				ab2+=player[team2[i]][team2[j]];
				ab2+=player[team2[j]][team2[i]];
			}
		}
//		for(int i=0;i<size;i++) cout<<team1[i]<<" ";
//		for(int j=0;j<size;j++) cout<<team2[j]<<" ";
//		cout<<team2[size-1];
//		cout<<"\n";
//		cout<<ab1<<" "<<ab2<<"\n";
		ans=min(abs(ab1-ab2),ans);	
		return;
	}
	
	for(int i=0;i<N;i++ ){
		if(!search(i)){
			team1[size]=i;
			sol(size+1);
		}
	}
	
	
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin>>player[i][j];
	}
//	cout<<"\n";
	sol(0);
	cout<<ans;
	return 0;
}
