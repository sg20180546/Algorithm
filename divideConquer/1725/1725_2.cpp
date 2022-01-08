#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int N;
long long h[100003];
long long ans;
stack <int> indexStack;

int main(){
	cin>>N;
	for(int i=1;i<=N;i++) cin>>h[i];
	h[N+1]=0;
	indexStack.push(0);
	
	for(int i=1;i<=N+1;i++){
		
		while(!indexStack.empty()&&h[indexStack.top()]>h[i]){
			
			long long topindex=indexStack.top();

			indexStack.pop();
			
			long long cur=h[topindex]*(i-1-indexStack.top());// ������ ���̴� h[topindex], ������ �������� i-1(���� �������� �� ������ �������� -1), �������� indexStack.top() -> ��� �߰��� ���������� �� 
			ans=max(cur,ans);
		}
		indexStack.push(i);
	}
	
	while(!indexStack.empty()){
		int a=indexStack.top();
		indexStack.pop();
		cout<<a<<" ";
	}
	cout<<"\n";
	
	cout<<ans;
	return 0; 
}
