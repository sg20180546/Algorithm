#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
string a,b,c;
int A=0,B=0,C=0;
int sub[27];
bool used[10];
bool alphabet[27];
bool possible;
int totalsize;

bool check(){
	for(int i=a.size()-1;i>=0;i--){
		A+=pow(10,i)*(sub[a[i]-65] );
	}
	for(int i=b.size()-1;i>=0;i--){
		B+=pow(10,i)*(sub[ b[i]-65]);
	}
	for(int i=c.size()-1;i>=0;i--){
		C+=pow(10,i)*(sub[ c[i]-65]);
	}

	return (A+B==C);
}


void dfs(int idx){
	if(idx==totalsize){
		if(check()){
			possible=true;
		}
		return;
	}
	string temp=a;
	int tempidx=idx;
	
	if(idx>=a.size()&&idx<a.size()+b.size()){
		tempidx-=a.size();
		temp=b;
	}
	else if(idx>=a.size()+b.size()){
		temp=c;
		tempidx-=a.size()+b.size();
	} 
	
	
	for(int i=0;i<temp.size();i++){
		for(int j=0;j<10;j++){
			if(alphabet[temp[i]]){
				dfs(idx+1);
			}
			if(used[j]) continue;
			
		}
	}
	
	
}

int main(){
	cin>>a>>b>>c;
	totalsize=a.size()+b.size()+c.size();
	for(int i=0;i<26;i++) sub[i]=-1;
	for(int i=0;i<a.size();i++) a[i]-=65;
	for(int i=0;i<b.size();i++) b[i]-=65;
	for(int i=0;i<c.size();i++) c[i]-=65;
	dfs(0);
	if(possible) cout<<"YES";
	else cout<< "NO";
}
