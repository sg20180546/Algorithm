#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector <string> v;
int map[6][6];


int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};


bool search(string s){
	for(int i=0;i<v.size();i++){
		if(s.compare(v[i])==0) return false;
	}
	return true;
}
void dfs(int x,int y,string str){
//	���ڿ��� 6�����Ǹ�, �˻��Ͽ� ���� �� return; 
	if(str.size()>5){
		if(search(str)){
			v.push_back(str);
		}
		return;		
	}
	
	for(int j=0;j<4;j++){
		int nx=x+dx[j];
		int ny=y+dy[j];
		if(nx<0||ny<0||nx>4||ny>4) continue;
		str.push_back(map[nx][ny]);
		dfs(nx,ny,str);
		str.pop_back();
	}
}


int main(){
	int num;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>num;
			map[i][j]=num+48;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
//			string�� ���������� �ƴ϶�, �� ��ȯ���� ���� ������ �ٸ����� ���⼭ �����ؾ��� 
			string str;
			str.push_back(map[i][j]);
			dfs(i,j,str);
		}
	}
	cout<<v.size();
	return 0;
}
