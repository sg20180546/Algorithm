#include <iostream>
#include <string>
using namespace std;

bool row[10][10];
bool column[10][10];
bool space[10][10];

int map[10][10];
bool fixen[10][10];
bool complete;
int transform(int i,int k){
	if(i<3) return k/3;
	else if(i<6&&i>=3) return k/3+3;
	else return k/3+6;
}

void dfs(int y,int x){
//	cout<<y<<" "<<x<<"\n";
	if(y==9){
		complete=true;
		return;
	}
	if(fixen[y][x]){
		if(x==8) dfs(y+1,0);
		else dfs(y,x+1);
		return;
	}
	int s=transform(y,x);
	for(int i=0;i<9;i++){
		if(complete) break;
		if(row[y][i]&&column[x][i]&&space[s][i]){
			map[y][x]=i+1;
			
			column[x][i]=false;
			row[y][i]=false;
			space[s][i]=false;
			
			if(x==8) dfs(y+1,0);
			else dfs(y,x+1);
			column[x][i]=true;
			row[y][i]=true;
			space[s][i]=true;
		}
	}
	
}

int main(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			row[i][j]=true;
			column[i][j]=true;
			space[i][j]=true;
		}
	}
	
	string s;
	for(int i=0;i<9;i++){
		cin>>s;
		for(int k=0;k<9;k++){
			if(s[k]!='0') fixen[i][k]=true; 
			map[i][k]=s[k]-48;
		}	
	}
	
	for(int i=0;i<9;i++){
		for(int k=0;k<9;k++){
			if(map[i][k]>0) row[i][map[i][k]-1]=false;	
		}	
	}
	for(int k=0;k<9;k++){
		for(int i=0;i<9;i++){
			if(map[i][k]>0) column[k][map[i][k]-1]=false;
		}
	}
	for(int i=0;i<9;i++){
		for(int k=0;k<9;k++){
			int s=transform(i,k);
			if(map[i][k]>0) space[s][map[i][k]-1]=false;
		}
	}
	
//	cout<<"\n";
	dfs(0,0);
	for(int i=0;i<9;i++){
		for(int k=0;k<9;k++){
			cout<<map[i][k];
		}
		cout<<"\n";
	}
	
	
	return 0;
}
