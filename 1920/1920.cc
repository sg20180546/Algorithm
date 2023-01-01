#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long ll;

int N;
int M;
unordered_set<ll> s;
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>N;
    while(N--){
        ll num;
        cin>>num;
        s.insert(num);
    }
    cin>>M;
    while(M--){
        ll num;
        cin>>num;
        auto iter= s.find(num);
        if(iter!=s.end()){
            cout<<1<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
}