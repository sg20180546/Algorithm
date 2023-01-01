#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int N;
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    ll num,a,b;
    ll ans;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        num=b-a;
        ll square=sqrt(num);
        if(square*square == num){
            ans=square*2-1;
        }else{
            ans=square*2;
            if(num>square*square+ square ){
                ans++;
            }
        }
        // if(num>square*(square+1)){
        //     ans++;
        // }
        cout<<ans<<"\n";
    }
}