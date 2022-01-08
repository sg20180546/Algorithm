#include <iostream>
#include <cmath>
using namespace std;


int N,row,column;
long long ans;
typedef long long ll;
void findPoint(ll a,ll b, ll c ,ll d){
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	if(column==a&&row==b){
		ans+=0;
		return;
	}
	if(column==a+1&&row==b+1){
		ans+=3;
		return;
	}
	
	if(column==a+1&&row==b){
		ans+=1;
		return;
	}
	if(column==a&&row==b+1){
		ans+=2;
		return;
	}
	
	ll midx=(a+c)/2;
	ll midy=(b+d)/2;
	ll width=c-a+1;
	ll height=d-b+1;
	if(column>midx){
		if(row>midy){
			ans+=(width)*(height)*3/4;
			findPoint(midx+1,midy+1,c,d);
		}else{
			ans+=width*height/4;
			findPoint(midx+1,b,c,midy);
		}
	}else{
		if(row>midy){
			ans+=width*height*2/4;
			findPoint(a,midy+1,midx,d);
		}else{
			ans+=0;
			findPoint(a,b,midx,midy);
		}
	}

	
}


int main(){
	cin>>N>>row>>column;
	int Npow=pow(2,N);
	findPoint(0,0,Npow-1,Npow-1);
	cout<<ans;
}
