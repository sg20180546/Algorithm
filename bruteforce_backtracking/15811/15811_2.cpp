#include <iostream>
#include <vector>
#include <string>

using namespace std;

char str[3][20];

int number[3];
int numOfalphabet[26]={-1};

bool isExistAlphabet[26]={false};
bool isUsedNumber[10]={false};

bool possible=false;

vector <int> alphabet;

int getNumber(string str){
	int result=0;
	int ind;
	for(int i=0;i<str.size();i++){
		ind=str[i]-'A';
		result=result*10+numOfalphabet[ind];
	}
	return result;
}

void dfs(int level){
	if(possible) return;
	if(level==alphabet.size()){
		for(int i=0;i<3;i++){
			number[i]=getNumber(str[i]);
		}
		if(number[0]+number[1]==number[2]){
			possible=true;
		}
	}else{
		for(int i=0;i<10;i++){
			if(!isUsedNumber[i]){
				isUsedNumber[i]=true;
				numOfalphabet[alphabet[level]]=i;
				dfs(level+1);
				isUsedNumber[i]=false;
			}
		}
	}
}

int main(){
	for(int i=0;i<3;i++) scanf("%s",str[i]);
	int ind;
	for(int k=0;k<3;k++){
		for(int i=0;str[k][i]!='\0';i++){
			ind=str[k][i]-'A';
			if(!isExistAlphabet[ind]) isExistAlphabet[ind]=true;
		}
	}
	for(int i=0;i<26;i++){
		if(isExistAlphabet[i]) alphabet.push_back(i);
	}
	dfs(0);
	if(possible) cout<<"YES";
	else cout<<"NO";
}
