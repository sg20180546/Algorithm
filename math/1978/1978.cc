#include <iostream>
#include <cstring>

bool isprime[1001];


int N;
int main(){
    int ans =0;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<100;i++){
        for(int j=2;i*j<1001;j++){
            isprime[i*j]=false;
        }
    }
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int n;
        scanf("%d",&n);
        if(isprime[n]){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}