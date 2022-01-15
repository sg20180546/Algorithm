#include <iostream>

#include <deque>


using namespace std;
int skill[1000001];
deque <int> initial;
int N;

int main(){
	int a;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>skill[i];
	}
	
	for(int i=1;i<=N;i++){
		int temp;
		switch(skill[N-i]){
			case 1:
				initial.push_back(i);
				break;
			case 2:
				temp=initial.back();
				initial.pop_back();
				initial.push_back(i);
				initial.push_back(temp);
				break;
			case 3:
				initial.push_front(i);
				break;
			default:
				break;
		}
	}
	
	while(!initial.empty()){
		cout<<initial.back()<<" ";
		initial.pop_back();
	}
	
}
