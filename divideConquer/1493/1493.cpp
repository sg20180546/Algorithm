#include <iostream>
#include <cmath>
using namespace std;

int cube[21];
int length,width,height,N;
int maxShape;
int ans=0;
bool possible=true; 
int cubesize;

void makeBox(int l,int w,int h){
	int ll=l;
	int ww=w;
	int hh=h;
	if(h==0) return;
	int k;
//	int cubesize;
//	큐브 선택 
	for(k=maxShape;k>=-1;k--){
		if(k==-1) break;
		cubesize=pow(2,k);
		if(cubesize<=ll&&cubesize<=ww&&cubesize<=h&&cube[k]) break;
	}
	if(k==-1){
		possible=false;
		return;
	}
	ans++;
	cube[k]--;
	makeBox(l,w,h-cubesize);
	makeBox(l-cubesize,w,cubesize);
	makeBox(l,w-cubesize,cubesize);
	
	
}


int main(){
	cin>>length>>width>>height;
	cin>>N;
	for(int i=0;i<21;i++) cube[i]=0;
	
	for(int i=0;i<N;i++){
		int shape,num;
		cin>>shape>>num;
		cube[shape]=num;
		maxShape=shape;
	}
	if(length>width){
		if(width>height){
			
		}else if(width<height){
			
			
		}
	}else{
		
	}
	makeBox(length,width,height);
	if(!possible) cout<<-1;
	else cout<<ans;
//	cout<<ans;
	return 0;
}
