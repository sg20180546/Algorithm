#include <iostream>
#include <algorithm>

using namespace std;

int N,K,M;
int arr[1000001];
int ans;
bool check(int p){
	int cnt=0;
	for(int i=0;i<N;i++){
		if(arr[i]>=2*K){
			cnt+=(arr[i]-2*K)/p;
		}else if(arr[i]<2*K&&arr[i]>K){
			cnt+=(arr[i]-K)/p;
		}
	}
	if(cnt>=M){
//		cout<<"p: "<<p<<"cnt: "<<cnt<<"\n";
		return (cnt>=M);
	}
	return false;
//	return (cnt>=M);
}
void binarySearch(int st, int ed){
	if(st>ed) return;
	int mid=(st+ed)/2;
	if(check(mid)){
		ans=max(ans,mid);
		binarySearch(mid+1,ed);
	}
	else binarySearch(st,mid-1);
}
int main(){
	
	cin>>N>>K>>M;
	int maxLen=0;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		maxLen=max(maxLen,arr[i]);
	}
	ans=-1;
	binarySearch(1,maxLen-K);
	cout<<ans;
	return 0;
}
