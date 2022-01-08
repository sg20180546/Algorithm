#include <iostream>

using namespace std;
int N,M;
int video[100000];
int maxtime=0,sum=0,blueray;

bool testBlueray(){
	bool insertedVideo[100000];
	for(int i=0;i<N;i++) insertedVideo[i]=false;
	int j=0;
	for(int i=0;i<M;i++){
		int temp=blueray;
		for(;j<N&&(temp-video[j]>=0);j++){
			temp-=video[j];
			insertedVideo[j]=true;
//			cout<<video[j]<<" ";
		}
//		cout<<"\n";
	}
	if(insertedVideo[N-1]){
		return true;
	}
	blueray++;
	return false;
}


int main(){
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		int time;
		cin>>time;
		video[i]=time;
		sum+=time;
		if(time>maxtime) maxtime=time;
	}
	blueray=max(sum/M,maxtime);
	while(!testBlueray()){
//		cout<<"hello";
	}
	cout<<blueray;
	
}
