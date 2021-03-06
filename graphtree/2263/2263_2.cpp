#include <iostream>
#define MAX 100001
using namespace std;
int N;
int inorder[MAX],postorder[MAX],idx[MAX];

void printPreorder(int inBegin,int inEnd, int postBegin, int postEnd){
//	cout<<inBegin<<" "<<inEnd<<" "<<postBegin<<" "<<postEnd<<"\n";
	if(inBegin>inEnd||postBegin>postEnd) return;
	int root=postorder[postEnd];
	cout<<root<<" ";
	printPreorder(inBegin,idx[root]-1,postBegin,postBegin+(idx[root]-inBegin)-1);//-1 cause +1 is root
	printPreorder(idx[root]+1,inEnd,postBegin+(idx[root]-inBegin),postEnd-1);
}

int main(void){
	cin>>N;
	for(int i=0;i<N;i++) cin>>inorder[i];
	for(int i=0;i<N;i++) cin>>postorder[i];
	for(int i=0;i<N;i++) idx[inorder[i]]=i;
//	for(int i=0;i<N+1;i++) cout<<idx[i]<<" ";
	printPreorder(0,N-1,0,N-1);
}
