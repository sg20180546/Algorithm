#include <iostream>
using namespace std;

// bottom-up

typedef long long ll;

#define max(a,b) (a)>(b) ? (a) : (b)


ll dp[1001];
ll price[10001];

int N;

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>price[i];
    }
    price[0]=0;

    for(int j=1;j<=N;j++){
        ll q=INT64_MIN;
        for(int i=1;i<=j;i++){
            q=max(q,price[i]+dp[j-i]);
        }
        dp[j]=q;
    }
    cout<<dp[N];
}