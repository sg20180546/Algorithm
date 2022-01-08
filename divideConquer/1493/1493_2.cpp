#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct var{
	int a,b=0;
};

bool cmp(var t1,var t2){
	if(t1.a>t2.a) return true;
	return false;
}

int l,w,h,n;
int result=0;
var arr[20];
bool jud=true;
void solved(int ll,int ww,int hh){
	if(jud==false) return;
	if(ll==0||ww==0||hh==0) return;
	
	for(int i=0;i<n;i++){
		if(ll>=arr[i].a&&ww>=arr[i].a&&hh>=arr[i].a&&arr[i].b>0){
			arr[i].b--;
			result++;
			solved(ll,ww,hh-arr[i].a);
			solved(arr[i].a,ww-arr[i].a,arr[i].a);
			solved(ll-arr[i].a,ww,arr[i].a);
			return;
		}
	}
	jud=false;
}
int main(){
	cin>>l>>w>>h;
	cin>>n;
	int temp1,temp2;
	for(int i=0;i<n;i++){
		cin>>temp1>>temp2;
		arr[i].a=pow(2,temp1);
		arr[i].b=temp2;
	}
	sort(arr,arr+n,cmp);
	solved(l,w,h);
	if(jud==false) cout<<-1;
	else cout<<result;
	return 0;
}
