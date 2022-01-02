#include <iostream>

#include <vector>

using namespace std;

vector <vector <int>> blue(1000);
vector <vector <int>> red(1000);
vector <int> state;
int N,ans;

void redt(int point,int parent){
	if(state.size()==4){
		if(state[0]==state[3]){
			ans++;
//			for(int i=0;i<4;i++) cout<<state[i]<<" ";
//			cout<<"\nans: "<<ans<<"\n"; 
//			cout<<"hello";
		}
//		cout<<"hello";
		return;
	}
	for(int i=0;i<red[point].size();i++){
		int a=red[point][i];
		if(a==parent) continue;
		state.push_back(a); 
		redt(a,point);
		state.pop_back();
	}
}


void bluet(int point,int parent){
	if(state.size()==4){
		if(state[0]==state[3]){
			ans++;
//			for(int i=0;i<4;i++) cout<<state[i]<<" ";
//			cout<<"\nans: "<<ans<<"\n"; 

		}
//		cout<<"hello";
		return;
	}
//	cout<<red[point].size()<<" ";
	for(int i=0;i<blue[point].size();i++){
		int a=blue[point][i];
		if(a==parent) continue;
		state.push_back(a); 
		bluet(a,point);
		state.pop_back();
	}
}


int main(){
	cin.tie(0);
	cout.tie(0); ios::sync_with_stdio(false);
	cin>>N;
	
	for(int i=0;i<N;i++){
		ans=0;
		int pn;
		cin>>pn;
		for(int j=1;j<pn;j++){ //4¹ø ¹Ýº¹ 
			for(int k=j+1;k<=pn;k++){ //
				int color;
				cin>>color;
				if(color==1){	
					red[j].push_back(k);
					red[k].push_back(j);
				}else if(color==0){
					blue[j].push_back(k);
					blue[k].push_back(j);
				}
				
			}
		}
		
	for(int i=1;i<=pn;i++){
		state.push_back(i);
		redt(i,-1);
		state.pop_back();
	}
	for(int i=1;i<=pn;i++){
		state.push_back(i);
		bluet(i,-1);
		state.pop_back();
	}
	cout<<ans/6<<"\n";		
	for(int i=1;i<=pn;i++){
		while(!blue[i].empty()){
			 blue[i].pop_back();
		}
		while(!red[i].empty()){
			red[i].pop_back();
		}
	}
		
	}
	
	
}
