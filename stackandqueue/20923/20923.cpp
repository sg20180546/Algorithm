#include <iostream>
#include <deque>
using namespace std;

deque <int> dodeck;
deque <int> sudeck;
deque <int> dofloor;
deque <int> sufloor;


int N,M;
bool turn=true;
void haligali(){
	int i=0;
	while(i<M){
//		cout<<dodeck.size()<<" "<<sudeck.size()<<"\n";
		if(turn){
//			cout<<"do turn\n";
			dofloor.push_back(dodeck.back());
			dodeck.pop_back();
		}else{
//			cout<<"su turn\n";
			sufloor.push_back(sudeck.back());
			sudeck.pop_back();
		}
		i++;
		turn=!turn;

		if(dodeck.empty()||sudeck.empty()) break;
		
		if(!sufloor.empty()&&!dofloor.empty()){
			if(sufloor.back()+dofloor.back()==5){
//				cout<<"suwin "<<" \n";
//				cout<<sufloor.back()<<" "<<dofloor.back()<<"\n";
				while(!dofloor.empty()){
					sudeck.push_front(dofloor.front());
					dofloor.pop_front();
				}
				while(!sufloor.empty()){
					sudeck.push_front(sufloor.front());
					sufloor.pop_front();
				}
				
				continue;
			}	
		}
		if(!sufloor.empty()){
			if(sufloor.back()==5){
//				cout<<"dowin"<<"\n";
				while(!sufloor.empty()){
					dodeck.push_front(sufloor.front());
					sufloor.pop_front();
				}	
				while(!dofloor.empty()){
					dodeck.push_front(dofloor.front());
					dofloor.pop_front();
				}
				continue;
			}
		}
		if(!dofloor.empty()){
			if(dofloor.back()==5){
//				cout<<"dowin"<<"\n";
				while(!sufloor.empty()){
					dodeck.push_front(sufloor.front());
					sufloor.pop_front();
				}	
				while(!dofloor.empty()){
					dodeck.push_front(dofloor.front());
					dofloor.pop_front();
				}
				continue;
			}
		}
		
	}
}

int main(){
	int D,S;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>D>>S;
		dodeck.push_back(D);
		sudeck.push_back(S);
	}
	haligali();
	if(sudeck.size()==dodeck.size()) cout<<"dosu";
	else if(sudeck.size()>dodeck.size()) cout<<"su";
	else cout<<"do";
}
