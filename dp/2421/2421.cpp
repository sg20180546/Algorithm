#include <iostream>
#include <assert.h>
using namespace std;
#define NOT_CALCUL -1
#define NOT_COMPOSITE 0
#define COMPOSITE 1
int save;
int dp[2000];
uint32_t is_composite[999999];

// void is_compsite(int a){

//     for(int i=2;)
// }

void cal(int num){
    for(int i=2;i<num;i++){
        if(num%i==0){
             
            is_composite[num]=NOT_COMPOSITE;
            return;
        }
    }
    is_composite[num]=COMPOSITE;
}
void sol(int a, int b,int n){
    if(a>=999||b>=999){
        return;
    }
    int num=a*10+b;
    if(is_composite[num]==NOT_CALCUL){
        cal(num);
    }
    assert(is_composite[num]!=NOT_CALCUL);
    int cnt=dp[n-1]+is_composite[num];
    if(dp[n]<cnt){
        // if(num<55)
        //     printf("num %d %d %d %d\n",num,cnt,n,is_composite[num]);
        dp[n]=cnt;
        sol(a+1,b,n+1);
        sol(a,b+1,n+1);
    }
}
// 11 12 21
int main(){
    int i;
    for(i=0;i<2000;i++){
        dp[i]=INT32_MIN;
        is_composite[i]=NOT_CALCUL;
    }
    for(;i<999999;i++){
        is_composite[i]=NOT_CALCUL;
    }
    dp[0]=0;
    // dp[1]=1;
    cin>>save;
    sol(1,1,0);
    // for(int i=0;i<30;i++)
    // {   
    //     // printf("num %d %s\n",i,is_composite[i] == COMPOSITE ? "cOMPSITE" : "NOT");
    //     cout<<i<<":"<<dp[i]<<"\n";
    // }
    cout<<dp[save]<<"\n";
    // printf("ans : %d\n",dp[save]);
}