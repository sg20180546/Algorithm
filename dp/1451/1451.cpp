#include <iostream>
#include <string>
using namespace std;
int N,M;
int ans;
long long map[51][51];

long long case1=0,case2=0,case3=0;

void printit(int row,int col,long long ans,int casen){
	cout<<"\ncasenumber : "<<casen<<" "<<row<<" "<<col<<" "<<ans<<"\n";
}

long long c1(int row,int col){
	long long upper=0;
	int i;
	for(i=0;i<row;i++){
		for(int k=0;k<M;k++){
			upper+=map[i][k];
		}
	}
	long long left=0,right=0;
	for(;i<N;i++){
		for(int k=0;k<M;k++){
			if(k<col) left+=map[i][k];
			else right+=map[i][k];
		}
	}
	
	long long ans= (upper*left*right);
//	printit(row,col,ans,1);
	
	return ans;
}
long long c2(int row,int col){
	long long left=0,upper=0,bottom=0;
	int i;
	for(i=0;i<row;i++){
		for(int k=0;k<M;k++){
			if(k<col) left+=map[i][k];
			else upper+=map[i][k];
		}
	}
	for(;i<N;i++){
		for(int k=0;k<M;k++){
			if(k<col) left+=map[i][k];
			else bottom+=map[i][k];
		}
	}
	long long ans=(left*upper*bottom);
//	printit(row,col,ans,2);
	return ans;
}
long long c3(int row,int col){
	long long left=0,right=0,bottom=0;
	int i;
	for(i=0;i<row;i++){
		for(int k=0;k<M;k++){
			if(k<col) left+=map[i][k];
			else right+=map[i][k];
		}
	}
	for(;i<N;i++){
		for(int k=0;k<M;k++){
			bottom+=map[i][k];
		}
	}
	
//	printit(row,col,ans,3);
	long long ans=(left*right*bottom);
//	printit(row,col,ans,3);
	return ans;
}
long long c4(int row,int col){
	long long upper=0,bottom=0,right=0;
	int i;
	for(i=0;i<col;i++){
		for(int k=0;k<N;k++){
			if(k<row) upper+=map[k][i];
			else bottom+=map[k][i];
		}
	}
	for(;i<M;i++){
		for(int k=0;k<N;k++){
			right+=map[k][i];
		}
	}
	
	long long ans=(upper*bottom*right);
//	printit(row,col,ans,4);
	return ans;
}


int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++) map[i][j]=0;
	}
	
	for(int i=0;i<N;i++){
			string s;
			cin>>s;
			for(int k=0;k<M;k++) map[i][k]=s[k]-48; 
		
	}
	
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			long long temp=max(c1(i,j),max(c2(i,j),max(c3(i,j),c4(i,j))));
			if(temp>case1) case1=temp;
		}
	}
	
	for(int i=1;i<N;i++){
		for(int j=i+1;j<N;j++){
//			cout<<"hello\n";
			int row,column;
			long long upper=0;
			for(row=0;row<i;row++){
				for(column=0;column<M;column++) upper+=map[row][column];
			}
			long long middle=0;
			for(;row<j;row++){
				for(column=0;column<M;column++){
					middle+=map[row][column];
				}
			}
			long long bottom=0;
			for(;row<N;row++){
				for(column=0;column<M;column++) bottom+=map[row][column];
			}
			if(case2<upper*middle*bottom) case2=upper*middle*bottom;
		}
	}
	
	for(int i=1;i<M;i++){
		for(int j=i+1;j<M;j++){
			int row,column;
			long long left=0;
			for(column=0;column<i;column++){
				for(row=0;row<N;row++) left+=map[row][column];
			}
			long long middle=0;
			for(;column<j;column++){
				for(row=0;row<N;row++) middle+=map[row][column];
			}
			long long right=0;
			for(;column<M;column++){
				for(row=0;row<N;row++) right+=map[row][column]; 
			}
			
			if(case3<left*middle*right) case3=left*middle*right;
		}
	}
	cout<<max(case1,max(case2,case3));
	return 0;
}
