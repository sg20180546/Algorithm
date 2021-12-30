#include <iostream>
#include <cstring>

using namespace std;
int R,C;
int ans;
int map[20][20];
bool search(int,int*,int);
int dfs(int* history,int r, int c,int i);


int main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	int firstR,firstD;
	int history[26];
	cin>>R>>C;
	for(int i=0;i<R;i++){
		string a;
		cin>>a;
		for(int j=0;j<C;j++){
			map[i][j]=a[j];
		}
	}

	ans=dfs(history,0,0,0);

	cout<<ans;	
	return 0;
}
int dfs(int* history,int r, int c,int i){
	
	if(search(map[r][c],history,i) ){
		return i;
	}
	i++;
	int* dest=new int[i];
	memcpy(dest,history,sizeof(int)*(i-1));
	dest[i-1]=map[r][c];
	
	int a1,a2,a3,a4;
	a1=a2=a3=a4=i;
	
	if(c+1<C){
		a1=dfs(dest,r,c+1,i);	
	} 
	if(r+1<R){
		a3=dfs(dest,r+1,c,i);	
	} 
	if(c-1>=0){
		a2=dfs(dest,r,c-1,i);	
	} 
	if(r-1>=0){
		a4=dfs(dest,r-1,c,i);
	} 
	
	delete dest;
	return max(max(max(a1,a2),a3),a4);
}




bool search(int N,int* array,int size){
	for(int i=0;i<size;i++){
		if(array[i]==N){
//			printf("array[%d] = %d, size: %d\n",i,N,size);
			return true;
		}
	}
	return false;
}






