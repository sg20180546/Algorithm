#include <stdio.h>
#include <memory.h>
// https://100100e.tistory.com/77
long ans[10];

void cal(long n,long i){
    while(n){
        ans[n%10]+=i;
        n/=10;
    }
}
void sol(int start,int end,int n){
    while(start%10&&start<=end){
        cal(start,n);
        start++;
    }
    if(start>end){
        return;
    }
    while(end%10!=9&&end>=start){
        cal(end,n);
        end--;
    }
    long diff=(end/10 - start/10 +1);
    int i;
    for(i=0;i<10;++i){
        ans[i]+=diff*n;
    }
    sol(start/10,end/10,n*10);
}

int main(){
    int T;
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        memset(ans,0,sizeof(long)*10);
        long n;
        scanf("%ld",&n);
        sol(1,n,1);
        for(n=0;n<10;n++){
            printf("%ld ",ans[n]);
        }
        printf("\n");
    }
}