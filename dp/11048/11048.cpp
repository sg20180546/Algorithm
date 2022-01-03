#include <iostream>

using namespace std;

int map[1001][1001];
int N,M;


int main(){
	cin>>N>>M;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(i==1&&j==1) map[i][j]=map[i][j];
			else if(i==1){
				map[i][j]+=map[i][j-1]; 
			}else if(j==1){
				map[i][j]+=map[i-1][j];
			}else{
				map[i][j]=map[i][j]+ max(map[i-1][j],(max(map[i-1][j-1],map[i][j-1])));
			}
		}
	}
	cout<<map[N][M];
	
	
	return 0;
}
