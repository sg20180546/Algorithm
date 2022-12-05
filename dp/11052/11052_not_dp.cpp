#include <iostream>
using namespace std;
typedef long long ll;
int N;
int price[1001];

// not dp
#define max(a,b) (a)>(b) ? (a) : (b)
int recursive(int n){
    if(n==0){
        return 0;
    }
    ll ret=INT64_MIN;
    for(int i=1;i<=n;i++){
        ret=max(ret,price[i]+recursive(n-i));
    }

    return ret;
}


int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>price[i];
    }

    cout<<recursive(N);

}