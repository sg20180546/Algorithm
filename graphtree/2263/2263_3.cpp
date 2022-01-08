#include <iostream>

using namespace std;
int inorder[100001];
int postorder[100001];
int idx[100001];
int N;
void printPreorder(int inBegin,int inEnd, int postBegin,int postEnd){
	if(inBegin>inEnd||postBegin>postEnd) return;
	int root=postorder[postEnd];
	cout<<root<<" ";
	printPreorder(inBegin,idx[root]-1,postBegin,postBegin+(idx[root]-inBegin)-1);
	printPreorder(idx[root]+1,inEnd,postBegin+(idx[root]-inBegin),postEnd-1);
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>inorder[i];
	for(int i=0;i<N;i++) cin>>postorder[i];
	for(int i=0;i<N;i++) idx[inorder[i]]=i;
	
	printPreorder(0,N-1,0,N-1);
}
