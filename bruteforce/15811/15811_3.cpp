#include <iostream>
#include <vector>
#include <string>
using namespace std;

string source[3];
int number[3];
bool possible;
bool usedNumber[10];
int alphabet[26];
vector <int> usingAlphabet;
bool usedAlphabet[26];

int transform(string str){
	int result=0;
	for(int i=0;i<str.size();i++){
		result=result*10+alphabet[str[i]-'A'];
	}
	
	return result;
}


void dfs(int idx){
	if(possible) return;
	if(idx==usingAlphabet.size()){
		for(int i=0;i<3;i++){
			number[i]=transform(source[i]);
		}
		if(number[0]+number[1]==number[2]){
			possible=true;
		}
		return;
	}
	for(int i=0;i<10;i++){
		if(possible) return;
		if(usedNumber[i]) continue;
		
		usedNumber[i]=true;
		alphabet[usingAlphabet[idx]]=i;
		dfs(idx+1);
		usedNumber[i]=false;
		
	}
	
}


int main(){
	for(int i=0;i<3;i++){
		cin>>source[i];
	}
	for(int i=0;i<3;i++){
		for(int k=0;k<source[i].size();k++){
			int a=source[i][k]-'A';
			if(!usedAlphabet[a]) usedAlphabet[a]=true;
		}
	}
	for(int i=0;i<26;i++){
		if(usedAlphabet[i]) usingAlphabet.push_back(i);
	}
	
	
	dfs(0);
	if(possible) cout<<"YES";
	else cout<<"NO";
	
}
