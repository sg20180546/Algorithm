#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

ll N;
ll B,C;
ll arr[1000001];
ll ans;

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cin>>B>>C;


    for(int i=0;i<N;i++){
        arr[i]-=B;
    }
    ans+=N;


    for(int i=0;i<N;i++){
        ll tmp=arr[i]/C;
        
        if(arr[i]>0){
            ans+=tmp;
            arr[i]-=tmp*C;
        }

        if(arr[i]>0){
            ans++;
        }
    }
    cout<<ans<<"\n";
}