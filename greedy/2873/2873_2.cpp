#include <iostream>
#include <cstring>
using namespace std;
int R,C;
string ans;
long long map[1001][1001];
long long MIN=999999;

pair <int,int> minindex;


void greedy(){
	bool state=true;
	bool state2=true;
	if(R%2==1){
		for(int i=1;i<R;i++){
			if(state){
				for(int j=1;j<C;j++) ans.push_back('R');
				state=false;
			}else{
				for(int j=1;j<C;j++) ans.push_back('L');
				state=true;
			}
			
			ans.push_back('D');
		}
		for(int j=1;j<C;j++) ans.push_back('R');
	}
	
	else if(R%2==0&&C%2==1){
		for(int i=1;i<C;i++){
			if(state){
				for(int j=1;j<R;j++) ans.push_back('D');
				state=false;
			}else{
				for(int j=1;j<R;j++) ans.push_back('U');
				state=true;
			}
			ans.push_back('R');
		}
		
		for(int j=1;j<R;j++) ans.push_back('D');
	}
	
	
	else if((R%2==0)&&(C%2==0)){
		if(minindex.first%2==1){
			for(int i=1;i<minindex.first;i++){
				if(state){
					for(int j=1;j<C;j++) ans.push_back('R');
					state=false;
				}else{
					for(int j=1;j<C;j++) ans.push_back('L');
					state=true;
			}
				ans.push_back('D');
			}
			state=true;
			for(int i=0;i<minindex.second;i++){
				if(state){
					ans.push_back('D');
					state=false;
				}else{
					ans.push_back('U');
					state=true;
				}
				ans.push_back('R');
//				ans.push_back('qwetwq');
			}
			state=true;
			for(int i=minindex.second+1;i<C;i++){
				ans.push_back('R');
				if(state){
					ans.push_back('D');
					state=false;
				}else{
					ans.push_back('U');
					state=true;
				}
			}
			state=true;
			for(int i=minindex.first+1;i<R;i++){
				ans.push_back('D');
				if(state){
					for(int j=1;j<C;j++) ans.push_back('L');
					state=false;
				}else{
					for(int j=1;j<C;j++) ans.push_back('R');
					state=true;
				}
			}
		
		
		}else{
			for(int i=0;i<minindex.first;i++){
				if(state){
					for(int j=1;j<C;j++) ans.push_back('R');
					state=false;
				}else{
					for(int j=1;j<C;j++) ans.push_back('L');
					state=true;
			}
				ans.push_back('D');
			}
			
			state=true;
			for(int i=0;i<minindex.second;i++){
				if(state){
					ans.push_back('D');
					state=false;
				}else{
					ans.push_back('U');
					state=true;
				}
				ans.push_back('R');
			}
			state=true;
			for(int i=minindex.second+1;i<C;i++){
				ans.push_back('R');
				if(state){
					ans.push_back('U');
					state=false;
				}else{
					ans.push_back('D');
					state=true;
				}
			}
			state=true;
			for(int i=minindex.first+2;i<R;i++){
				ans.push_back('D');
				if(state){
					for(int j=1;j<C;j++) ans.push_back('L');
					state=false;
				}else{
					for(int j=1;j<C;j++) ans.push_back('R');
					state=true;
				}
			}
		}
	}
}



int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			long long a;
			cin>>a;
			map[i][j]=a;
			
			if( (i%2==1&&j%2==0) || (i%2==0&&j%2==1)){
				if(a<MIN){
					MIN=a;
					minindex.first=i;
					minindex.second=j;
				}
		}
	}
	}


	greedy();
	cout<<ans;
	
}
