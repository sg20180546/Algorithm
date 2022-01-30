#include <iostream>
#include <vector>
using namespace std;

bool possible;
int N,M,K,maxn,ans;
vector<int> vec;

bool check(int cm){
	int cnt=0;
	
	for(int i=0;i<vec.size();i++){
		if(vec[i]>=2*K){
			cnt+=(vec[i]-2*K)/cm;
		}
		else if(vec[i]>K){
			cnt+=(vec[i]-K)/cm;
		}
	}
	return (cnt>=M);
}

int main(){
	int g;
	cin>>N>>K>>M;
	for(int i=0;i<N;i++){
		cin>>g;
		vec.push_back(g);
		maxn=max(maxn,g);
	}
	int start=1,end=maxn-K;
	
	while(start<=end){
		int mid=(start+end)/2;
		if(check(mid)){
			possible=true;
			start=mid+1;
			ans=mid;
		}else{
			end=mid-1;
		}
	}
	if(possible) cout<<ans;
	else cout<<-1;
}

