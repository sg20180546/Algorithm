#include <iostream>
#include <cstring>
using namespace std;
int INF=1<<31-1;
int dx[5]={0,0,-1,1,0};
int dy[5]={0,-1,0,0,1};

int row,col,A[20][20],B[20][20],C[20][20],ans[20][20];

bool isRange(int x, int y){
	if(x<0||x==row||y<0||y==col) return false;
	else return true;
}

void toggle(int x, int y){
	for(int i=0;i<5;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(isRange(nx,ny)) B[nx][ny]^=1;
	}
}
int func(int topState){
	int ret=0;
	memcpy(B,A,sizeof(A));
	memset(C,0,sizeof(C));
//	cout<<topState<<" ";
	for(int i=0;i<col;i++){
		if(topState&(1<<i)){
			C[0][i]=1;
			toggle(0,i);
			ret++;
//			cout<<i<<" ";
		}
}
	for(int i=1;i<row;i++){
		for(int j=0;j<col;j++){
			if(B[i-1][j]){
				++ret;
				C[i][j]=1;
				toggle(i,j);
			}
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(B[i][j]==1) return INF;
		}
	}
	return ret;
}
int main(){

	cin>>row>>col;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++) cin>>A[i][j];
	}
	int mmin=INF;
//	1<<col : 모든 경우의 수 00000, 00001 
	for(int i=0;i<(1<<col);i++ ){
		int ret=func(i);
		if(ret<mmin){
			mmin=ret;
			memcpy(ans,C,sizeof(C));
		}
	}
//	cout<<"\n";
	if(mmin==INF) cout<<"IMPOSSIBLE";
	else{
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}
