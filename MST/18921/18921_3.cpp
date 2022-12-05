#include <iostream>

using namespace std;
int N;
long long map[100001][100001];
long long table[100001];

int main(){
    cin>>N;
    long long a,b,v;
    for(int i=0;i<N;i++){
        cin>>a>>b>>v;
        map[a][b]=v;
        map[b][a]=v;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]==0){
                continue;
            }
            
        }
    }
}
