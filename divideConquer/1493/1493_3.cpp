#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int length,width,height;
int N;
typedef struct{
	int size;
	int n;
}cube;
bool cmp(cube a, cube b){
	if(a.size>b.size) return true;
	return false;
}
bool possible=true;
int ans=0;
cube arr[21];
void makeBox(int l,int w,int h){
	if(l==0||w==0||h==0) return;
	if(!possible) return;
	for(int i=0;i<N;i++){
		if(arr[i].size<=l&&arr[i].size<=w&&arr[i].size<=h&&arr[i].n){
			arr[i].n--;
			ans++;
			makeBox(l,w,h-arr[i].size);
			makeBox(l-arr[i].size,arr[i].size,arr[i].size);
			makeBox(l,w-arr[i].size,arr[i].size);
			return;
		}
	}
	possible=false;
}


int main(){
	cin>>length>>width>>height;
	cin>>N;
	int kind,num;
	
	for(int i=0;i<N;i++){
		cin>>kind>>num;
		cube c;
		c.size=pow(2,kind);
		c.n=num;
		arr[i]=c;
	}
	
	sort(arr,arr+N,cmp);
	makeBox(length,width,height);
	
	if(!possible) cout<<-1;
	else cout<<ans;
	
	
	return 0;
}
