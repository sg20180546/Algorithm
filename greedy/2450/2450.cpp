#include <iostream>
#include <cstdlib>
using namespace std;

int N;

int a[100000];
int comp[100000];
int circle=0;
int triangle=0;
int square=0;

int check(){
	int ret=0;
	int case13=0;
	int case31=0;
	int case23=0;
	int case32=0;
	int case12=0;
	int case21=0;
	for(int i=0;i<N;i++){
		if(a[i]==1&&comp[i]==3) case13++;
		if(a[i]==3&&comp[i]==1) case31++;
		if(a[i]==1&&comp[i]==2) case12++;
		if(a[i]==2&&comp[i]==1) case21++;
		if(a[i]==2&&comp[i]==3) case23++;
		if(a[i]==3&&comp[i]==2) case32++;
	}
	ret+=min(case13,case31)+min(case21,case12)+min(case23,case32);
	case13=abs(case13-case31);
	case12=abs(case12-case21);
	case23=abs(case23-case32);
//	cout<<case13<<" "<<case12<<" "<<case23<<" ";
	int sum=2*(case13+case12+case23)/3;
	return ret+sum;
//	return ret;
}

int c123(){
	for(int i=0;i<triangle;i++) comp[i]=1;
	for(int i=triangle;i<square+triangle;i++) comp[i]=2;
	for(int i=square+triangle;i<N;i++) comp[i]=3;
	return check();
}
int c132(){
	for(int i=0;i<triangle;i++) comp[i]=1;
	for(int i=triangle;i<circle+triangle;i++) comp[i]=3;
	for(int i=circle+triangle;i<N;i++) comp[i]=2;
	return check();
}
int c213(){
	for(int i=0;i<square;i++) comp[i]=2;
	for(int i=square;i<square+triangle;i++) comp[i]=1;
	for(int i=square+triangle;i<N;i++) comp[i]=3;
	return check();
}
int c231(){
	for(int i=0;i<square;i++) comp[i]=2;
	for(int i=square;i<square+circle;i++) comp[i]=3;
	for(int i=circle+square;i<N;i++) comp[i]=1;
	return check();
}
int c312(){
	for(int i=0;i<circle;i++) comp[i]=3;
	for(int i=circle;i<triangle+circle;i++) comp[i]=1;
	for(int i=triangle+circle;i<N;i++) comp[i]=2;
	return check();	
}
int c321(){
	for(int i=0;i<circle;i++) comp[i]=3;
	for(int i=circle;i<square+circle;i++) comp[i]=2;
	for(int i=circle+square;i<N;i++) comp[i]=1;
	return check();
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int k;
		cin>>k;
		a[i]=k;
		if(k==1) triangle++;
		if(k==2) square++;
		if(k==3) circle++;
	}
	int a=c321();
	int b=c312();
	int c=c123();
	int d=c132();
	int e=c213();
	int f=c231();
	
	int ans=min(a,min(b,min(c,min(d,min(e,f)))));
	cout<<ans;
	return 0;
}
