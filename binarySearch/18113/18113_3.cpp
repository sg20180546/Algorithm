#include <iostream>

using namespace std;
int N,K,M;
int gimbab[1000001];
int ans;

bool check(int piece){
	int cnt=0;
	for(int i=0;i<N;i++){
		int cur=gimbab[i];
		if(cur>=2*K){
			cnt+=(cur-2*K)/piece;
		}else if(cur>K&&cur<2*K){
			cnt+=(cur-K)/piece;
		}
	}
	
	return (cnt>=M);
	
}


void binarySearch(int st,int ed){
	if(st>ed) return;
	int mid=(st+ed)/2;
	if(check(mid)){
		ans=max(ans,mid);
		binarySearch(mid+1,ed);
	}else{
		binarySearch(st,mid-1);
	}
	
}


int main(){
	cin>>N>>K>>M;
	int maxSize=0;
	for(int i=0;i<N;i++){
		int g;
		cin>>g;
		gimbab[i]=g;
		maxSize=max(g,maxSize);
	}
	ans=-1;
	binarySearch(1,maxSize-K);
	cout<<ans;
}
