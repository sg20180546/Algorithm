#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
string str;
queue <long long> s[22];
vector <long long> vec;
long long N,K;
long long ans=0;

void sol(){
	for(long long i=0;i<N;i++){
		if(s[vec[i]].empty()){
			s[vec[i]].push(i);	
		}
		else{
			while(!s[vec[i]].empty()&&i-s[vec[i]].front()>K){
				s[vec[i]].pop();
			}
			ans+=s[vec[i]].size();
			s[vec[i]].push(i);
		}
	}
}


int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>str;
		vec.push_back(str.size());
	}
	sol();
	cout<<ans;
//	int a=300000;
//	cout<<a*a;
//	cout<<300000*300000<<"";
}
