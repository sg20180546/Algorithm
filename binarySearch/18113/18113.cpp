#include <iostream>
#include <algorithm>
using namespace std;
long long N,K,M;
long long gimbab[1000000];


long long ans=-1;
void sol(){
	int index=-1;
	for(int i=0;i<N;i++){
		if(gimbab[i]>0){
			index=i;
			break;
		}
	}
	if(index<0||index>=N){
		return;
	}
	
	
	for(long long j=gimbab[index];j>=1;j--){
		int temp=0;
		for(int i=index;i<N;i++){
			if(gimbab[i]%j==0){
				temp+=gimbab[i]/j;
			}else{
				temp=-1;
				break;
			}
		}
		if(temp>=M){
			ans=j;
			break;
		}
	}
	
	
}

int main(){
	cin>>N>>K>>M;
	long long g;
	for(int i=0;i<N;i++){
		cin>>g;
		gimbab[i]=g;
	}
	bool possible=true; 
	for(int i=0;i<N;i++){
		if(gimbab[i]==2*K){
			possible=false;
			break;
		}
		else if(gimbab[i]>=2*K){
			gimbab[i]-=2*K;
		}
		else if(gimbab[i]>K&&gimbab[i]<2*K){
			gimbab[i]-=K;
		}else if(gimbab[i]<=K){
			gimbab[i]=0;
		}
	}
	
	sort(gimbab,gimbab+N);
	if(possible){
		sol();
		cout<<ans;
	}else{
		cout<<ans;
	}
}
