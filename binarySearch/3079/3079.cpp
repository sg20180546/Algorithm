#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N,M,ans;

vector <long long> pass;
bool check(long long t){
	long long cnt=0;
	for(int i=0;i<N;i++){
		cnt+=(t/pass[i]);
	}
//	cout<<cnt<<"\n";
	return (cnt>=M);
}

int main(){
	
	cin>>N>>M;
	long long start,end,mid,time;
	for(int i=0;i<N;i++){
		cin>>time;
		pass.push_back(time);
	}
	
	
	sort(pass.begin(),pass.end());
	end=pass[N-1]*M;
	start=1;
	while(start<=end){
		mid=start+(end-start)/2;
//		cout<<start<<" "<<mid<<" "<<end<<"\n";
		if(check(mid)){
			end=mid-1;
			ans=mid;
		}else{
			start=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
