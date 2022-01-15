#include <iostream>
#include <stack>
#include <string>
using namespace std;



#define LP '('
#define RP ')'
#define LMP '['
#define RMP ']'


string s;
int ans=0;
bool correct=true;
stack <char> st;
stack <int> S[31];

void calculate(){
	for(int i=0;i<s.size();i++){
		int size=st.size();
		int previousS=0;
		if(s[i]==LP||s[i]==LMP){
			st.push(s[i]);
		}
		
		else if(s[i]==RP){
			if(st.empty()||st.top()!=LP){
				correct=false;
				break;
			}
		while(!S[size+1].empty()){
			previousS+=S[size+1].top();
			S[size+1].pop();
		}
		if(previousS==0) previousS=1;
		S[size].push(2*previousS);
		st.pop();
		}
		
		else if(s[i]==RMP){
			if(st.empty()||st.top()!=LMP){
				correct=false;
				break;
			}
			while(!S[size+1].empty()){
				previousS+=S[size+1].top();
				S[size+1].pop();
			}
			
			if(previousS==0) previousS=1;
			S[size].push(3*previousS);
			st.pop();
		}
	}
}

int main(){
	cin>>s;
	calculate();
	if(correct){
		while(!S[1].empty()){
			ans+=S[1].top();
			S[1].pop();
		}
		cout<<ans;
	}else{
		cout<<0;
	}
}
