#include <iostream>
#include <cmath>

using namespace std;

//int map[32769][32769];

int N,row,column;
int Npow2;
int ans=0; 
bool anschange=false;
int i=0;
void Zs(int a,int b,int c, int d){
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<"\n";
	if(anschange) return;
	if(column==a&&row==b){
		ans=i;
		anschange=true;
		return;
	}
	if(column==a+1&&row==b+1){
		ans=i+3;
		anschange=true;
		return;
	}
	
	if(column==a+1&&row==b){
		ans=i+1;
		anschange=true;	
		return;
	}
	if(column==a&&row==b+1){
		ans=i+2;
		anschange=true;
		return;
	}
	if(c-a==1&&d-b==1){
		i+=4;
		return;
	}
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<"\n";
//	Zs(a,b,c/2,d/2);
//	Zs(c/2+1,b,c,d/2);
//	Zs(a,d/2+1,c/2,d);
//	Zs(c/2+1,d/2+1,c,d);
	
	Zs(a,b,(a+c)/2,(b+d)/2);
	Zs((a+c)/2+1,b,c,(b+d)/2);
	Zs(a,(b+d)/2+1,(a+c)/2,d);
	Zs((a+c)/2+1,(b+d)/2+1,c,d);
}


int main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>N>>row>>column;
	int Npow2=pow(2,N);
	//x,y
//	cout<<Npow2;

	Zs(0,0,Npow2-1,Npow2-1);
	cout<<ans;
}
