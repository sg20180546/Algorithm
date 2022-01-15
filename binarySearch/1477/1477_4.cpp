#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,L;
vector <int> map;
int road[1000];
int ans;
void binarySearch(int start,int end){
	if(start>end) return;
	int count=0;
	int mid=start+(end-start)/2;
	for(int i=0;i<N+1;i++){
//		if(i==N) cout<<road[0];
		if(road[i]>mid){
			if(road[i]%mid==0){
				count+=road[i]/mid-1;
			}else{
				count+=road[i]/mid;
			}
		}
	}
	if(count>M){
		binarySearch(mid+1,end);
	}else{
		ans=mid;
		binarySearch(start,mid-1);
	}
	
}

int main(){
	int r;
	cin>>N>>M>>L;
	for(int i=0;i<N;i++){
		cin>>r;
		map.push_back(r);
	}
	sort(map.begin(),map.end());
	if(N>0){
		road[0]=map[0];
		road[N]=L-map[N-1];		
	}
	if(N==0){
		road[0]=L;
	}
	for(int i=1;i<map.size();i++){
		road[i]=map[i]-map[i-1];
	}
	
	binarySearch(1,L);
	cout<<ans;
}
