#include <algorithm>
#include <iostream>

using namespace std;

int a[]={144,23,2,4};
bool cmp(int a ,int b){
//	if(a>b){
//		cout<<"a>b"<<" ";
//		return true;
//	}
	return (a<b);
}
int main(){
	
	sort(a,a+4,cmp);
	
	for(int i=0;i<4;i++) cout<<a[i]<<" ";
	
	return 0;
}
