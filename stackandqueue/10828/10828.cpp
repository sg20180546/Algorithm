#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <int> s;
string str;
int N;
int main(){
	cin.tie(0); cout.tie(0);
//	ios::sync_with_stdio(false);
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>str;
		if(str[0]=='p'&&str[1]=='u'){
			int num;
			cin>>num;
			s.push(num);
		}
		if(str[0]=='p'&&str[1]=='o'){
			if(!s.empty()){
				cout<<s.top()<<"\n";
				s.pop();
			}else{
				cout<<-1<<"\n";
			}
		}
		if(str=="size"){
			cout<<s.size()<<"\n";
		}
		if(str=="empty"){
			if(s.empty()) cout<<1<<"\n";
			else cout<<0<<"\n";
		}
		if(str=="top"){
			if(s.empty()) cout<<-1<<"\n";
			else cout<<s.top()<<"\n";
		}
	}
}
