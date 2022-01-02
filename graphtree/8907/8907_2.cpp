#include <iostream>


using namespace std;

void proc(){
	int one[1000];
	int zero[1000];
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		one[i]=0;
		zero[i]=0;
	}
	int total=N*(N-1)*(N-2)/6;
	int diff=0;
	
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			int num;
			cin>>num;
			if(num==1){
				one[i]++;
				one[j]++;
			}else if(num==0){
				zero[i]++;
				zero[j]++;
			}
		}
	}
	for(int i=1;i<=N;i++){
		diff+=one[i]*zero[i];
	}
	
	cout<<total-diff/2<<"\n";
}


int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		proc();	
	}
	
}
