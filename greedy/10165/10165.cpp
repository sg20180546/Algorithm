#include <iostream>
#include <vector>
using namespace std;
int N,M;
typedef struct{
	int n;
	int start;
	int end;
} subway;

vector <subway> v;
// s1이 현재 판단하는 노선 
void check(subway* s1,subway* s2){
//	cout<<"ASd";
	if(s2->start<s2->end){
		if(s1->start<s1->end){
			if((s1->start)>=s2->start&&(s1->end)<=(s2->end)){
				(*s1).n=-1;
			}
		}else{
			return;
		}
		
	}else{
		if(s1->start<s1->end){
			if(s1->start>=s2->start){
				(*s1).n=-1;
			}
			if(s1->end<=s2->end){
				(*s1).n=-1;
			}
		}else{
			if(s1->start>=s2->start&&s1->end<=s2->end){
//				cout<<"as";
				(*s1).n=-1;
			}
		}
	}
}

void greedy(){
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			if(i==j) continue;
			if(v[j].n==-1) continue;
			check(&v[i],&v[j]);
			
			if(v[i].n==-1) break;
		}
	}
}

int main(){
	cin>>N;
	cin>>M;
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		subway s;
		s.n=i+1;
		s.start=a;
		s.end=b;
		v.push_back(s);
	}
	
	greedy();
	for(int i=0;i<M;i++){
		if(v[i].n==-1) continue;
		cout<<v[i].n<<" ";
	}
	
	
	return 0;
}


