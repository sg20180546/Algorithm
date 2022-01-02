#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> inorder;
vector <int> postorder;
vector <int> preorder;

bool visit[100001];


// index -- postorder index;
void findPreorder(int index){
	if(visit[index]) return;
	int root=postorder[index];
	preorder.push_back(root);
	visit[index]=true;
	
	if(index==0){
		return;
	}
	
	int mid;
	
	for(int i=0;i<inorder.size();i++){
		if(root==inorder[i]) mid=i;
	}
	
	findPreorder(left);
	findPreorder(right);
}

int main(){
	int N,a;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>a;
		inorder.push_back(a);
	}
	for(int i=0;i<N;i++){
		cin>>a;
		postorder.push_back(a);
	}
	int index;
	for(int i=0;i<N;i++){
		if(postorder[N-1]==inorder[i]) index=i;
	}
	
	findPreorder(N-1);
	for(int i=0;i<preorder.size();i++) cout<<preorder[i]<<" ";
}
