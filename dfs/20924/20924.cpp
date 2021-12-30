#include <iostream>
#include <vector>
using namespace std;
int N,R;
int rootdis=0,gigadis=0;
int child[200001];
typedef struct{
	int parentNode=-1;
	int childNode=-1;
	int distance=0;
}element;
element parent[200001];
vector <element> vec;

bool unconnect(){
	if(vec.size()==N){
		return false;
	}
	
	return true;
}

bool search(int x){
	for(int i=0;i<vec.size();i++){
		if(vec[i].parentNode==x||x==R) return true;
	}
	return false;
}


int main(){

	
	cin>>N>>R;
	
//	for(int i=R;i<R+N;i++){
//		child[i]=0;
//	}
	element root;
	root.parentNode=R;
	parent[R]=root;
	
	vec.push_back(root);
	
	while(unconnect()){
		int par,chi,dis;
		cin>>par>>chi>>dis;
		element e;
		e.childNode=chi;
		e.parentNode=par;
		e.distance=dis;
		
		
		if(!search(par)){
			vec.push_back(e);
		}
		
		child[par]++;
		parent[par].childNode=chi;
		parent[chi].parentNode=par;
		parent[chi].distance=dis;
	}
	
	
	
	int temp=R;

	
	for(int i=temp;i<R+N;i=parent[i].childNode){
		if(child[i]>2||parent[i].childNode==-1){
			temp=i;
			break;
		}
		rootdis+=parent[parent[i].childNode].distance;
	}
	
	
	for(int i=temp;i<R+N;i++){
		int gigatemp=0;
		if(child[i]!=0) continue;
		else{
			for(int j=i;j!=temp;j=parent[j].parentNode){
				gigatemp+=parent[j].distance;
			}
		}
		gigadis=max(gigadis,gigatemp);
	}
	cout<<rootdis<<" "<<gigadis;
	
	return 0;
}



