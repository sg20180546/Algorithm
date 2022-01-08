#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,L;
int ans;
typedef struct{
	int distance;
	int n=1;
} road;

int map[1001];
road arr[1001];


road* search(){
	
}

int binarySearch(int l){
	int maxroad=max_element(road.begin(),road.end());
	if(l==0) return maxroad;
	int i=1;
	int remainder;
	while(i<=l){
		remainder=(*maxroad)%(i+1);
		for(int j=0;j<remainder;j++) road.push_back((*maxroad)/(i+1)+1);
		*maxroad/=2;
		int temp=binarySearch(l-i);
		if(ans>temp){
			ans=temp;
			maxroad*=2;
			for(int j=0;j<remainder;j++) road.erase(road.begin()+N,road.begin()+N+remainder);
		}
		i++;
	}
	
	return *max_element(road.begin(),road.end());
	
}

int main(){
	cin>>N>>M>>L;
	for(int i=0;i<1001;i++) map[i]=0;
	for(int i=0;i<N;i++){
		int rest;
		cin>>rest;
		map[i]=rest;
	}
	sort(map,map+1000,cmp);
	sort(map,map+N);
	road r;
	r.distance=map[0];
	arr[0]=r;
	r.distance=L-map[N-1];
	arr[N]=r;
	for(int i=1;i<N;i++){
		road r;
		r.distance=map[i]-map[i-1];
		arr[i]=r;
	}
	
	return 0;
}
