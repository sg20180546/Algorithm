#include <iostream>
#include <stack>
#include <string>
#define LP '('
#define RP ')'
#define LMP '['
#define RMP ']'
using namespace std;
stack <int> p;
string s;
int ans;
bool correct=true;
int calculate(){
	while(!p.empty()){
		int par=p.top();
		p.pop();
		switch(par){
			case RP:
				return calculate()*2;
			case RMP:
				return calculate()*3;
			case LP:
				return 2;
			case LMP:
				return 3;
		}	
	}
}
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		p.push(s[i]);
	}
	while(!p.empty()){
		ans+=calculate();
	}
	
	if(correct) cout<<ans;
	else cout<<0;
}

