#include <iostream>
using namespace std;

// top-down

typedef long long ll;

#define max(a,b) (a)>(b) ? (a) : (b)


ll dp[1001];
ll price[10001];

int N;
int cut_rod_aux(int n){
    if(dp[n]>0){
        return dp[n];
    }
    ll q=INT64_MIN;
    if(n==0){
        q=0;
    }else{
        for(int i=1;i<=n;i++){
            q=max(q,price[i]+cut_rod_aux(n-i));
        }
    }
    dp[n]=q;
    return dp[n];
}

int cut_rod(int n){
    for(int i=1;i<=N;i++){
        dp[i]=INT64_MIN;
    }
    return cut_rod_aux(n);
}



int main(){
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        cin>>price[i];
    }
    cout<<cut_rod(N);
}