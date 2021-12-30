#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std; 

int START=0;
int END=0;
int MID=0;
int result=1;
int N;
vector<pair<int,int>> vec;



void greedy(){
	START=vec[0].first;
	END=vec[0].second;
//	cout<<START<<" ";
	if(START!=301){
		result=0;
	}else{
		for(int i=1;i<N;i++){
			if(END==1201) break;
			
			int s=vec[i].first;
			int e=vec[i].second;
			if(s>END){
				result=0;
				break;
			}
			if(s==START&&e>END){
				END=e;
				continue;
			}
			if(s>START&&e>END&&s>MID){
				MID=END;
				END=e;
				START=s;
				result++;
				continue;
			}
			if(s>START&&e>END&&s<=MID){
				START=s;
				END=e;
				continue;
			}
			
		}
	}
}

int main(void){
	cin>>N;
	
	for(int i=0;i<N;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a<3){
			a=3;
			b=1;
		}
		if(c==12){
			d=1;
		}
		vec.push_back({a*100 +b, c*100 + d});
	}
	sort(vec.begin(),vec.end());
	greedy();

	if(END==1201) cout<<result;
	else cout<<0;	
	return 0;
}

