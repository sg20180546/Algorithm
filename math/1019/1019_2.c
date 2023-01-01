#include <stdio.h>

typedef long long ll;

ll ans[10];

void cal(ll num, ll ten){
    while(num){
        ans[num%10]+=ten;
        num/=10;
    }
}

void sol(ll start,ll end, ll ten){
    while(start%10!=0&&start<=end){
        cal(start,ten);
        start++;
    }
    if(start>end){
        return;
    }
    while(end%10!=9&&start<=end){
        cal(end,ten);
        end--;
    }
    ll diff=(end/10-start/10+1);
    int i;
    for(i=0;i<10;i++){
        ans[i]+=diff*ten;
    }
    sol(start/10,end/10,ten*10);
}


int main(){
    ll NUM;
    int T;
    // scanf("%d",&T);
    int j;
    // for(j=0;j<T;j++){
    scanf("%lld",&NUM);
    sol(1,NUM,1);
    int i;
        for(i=0;i<10;i++){
            printf("%lld ",ans[i]);
        }
    // }
}