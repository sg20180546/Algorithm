#include <iostream>
#include <stack>

using namespace std;
int N;
stack <int> s;
int ans=0;
int minheight[100000];
void histogram(){
	int width=1;
	int height=s.top();
	int area=width*height;
	s.pop(); 
	
	while(!s.empty()){
		if(s.top()>=height){
			if(height*(width+1)>s.top()){
				area=height*(width+1);
				width++;
			}else{
				width=1;
				area=s.top();
				height=s.top();
			}
			
			
		}else{
			if(area>s.top()*(width+1)){
				width++;
				height=s.top();
				
			}else{
				area=s.top()*(width+1);
				width++;
				height=s.top();
			}
			
		}
		ans=max(ans,area);
		s.pop();
		
	}
}


int main(){
	cin>>N;
	int min=1<<32-1;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		s.push(n);
		if(n<min) min=n;
		minheight[i]=min;
	}
	histogram();
	cout<<ans;
}
