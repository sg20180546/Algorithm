#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

long long N,M;

typedef struct bus{
	int num,a,b;
}Bus;

vector <bus> route1,route2;

bool compare(const Bus& f,const Bus& s){
	if(f.a!=s.a) return f.a<s.a;
	else return f.b>s.b;
}

bool able[500001];

int main(){
	cin>>N;
	cin>>M;
	long long minA=1e12, maxB=-1;
	for(int i=1;i<=M;i++){
		long long a,b;
		cin>>a>>b;
		Bus bus;
		bus.num=i;bus.a=a;bus.b=b;
		if(a<b){
			route1.push_back(bus);
		}else{
			minA=min(minA,a);
			maxB=max(maxB,b);
			
			bus.b=b+N;
			route2.push_back(bus);
		}
		able[i]=true;
	}
	sort(route1.begin(),route1.end(),compare);
	sort(route2.begin(),route2.end(),compare);
	
	int right=0;
	for(int i=0;i<route1.size();i++){
		if(minA<=route1[i].a) able[route1[i].num]= false;
		if(maxB>=route1[i].b) able[route1[i].num]=false;
		
		if(route1[i].b<=right){
			able[route1[i].num]=false;
		}else{
			right=route1[i].b;
		}
	}
	right=0;
	for(int i=0;i<route2.size();i++){

			if(route2[i].b<=right){
			able[route2[i].num]=false;
		}else{
			right=route2[i].b;

		}
	}
	
	for(int i=1;i<=M;i++){
		if(able[i]==true){
			cout<<i<<" ";
		}
	}
}
