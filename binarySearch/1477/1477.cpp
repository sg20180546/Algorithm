#include <iostream>
#include <algorithm>
using namespace std;
int N,M,L;

bool cmp(int a, int b){
	if(a>b) return true;
	return false;
}

int map[1001];
int road[1001];
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
	road[0]=map[0];
	road[N]=L-map[N-1];
	for(int i=1;i<N;i++){
		road[i]=map[i]-map[i-1];
	}
//	for(int i=0;i<N+1;i++) cout<<road[i]<<" ";
	
	int odd=0;
	int i;
	for(i=0;i<M;i++){
		int *dis=max_element(road,road+N+1+i);
//		cout<<*dis<<" ";
		if(*dis%2==1){
//			cout<<*(road+N+1+odd)<<"\n";
			*(road+N+1+i)=*dis/2+1;

		}else{
			*(road+N+1+i)=*dis/2;
		}
		*dis/=2;
	}
//	cout<<"\n";
//;	for(int j=;i<N+i;j++) cout<<road[j]<<" ";
	cout<<*max_element(road,road+N+i+1);
}
