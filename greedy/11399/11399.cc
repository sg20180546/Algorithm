#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int waiting_time[1000];
int N;
int ans=0;
vector<int> v;
using namespace std;


int main(){
    cin>>N;
    int t;
    while(N--){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    waiting_time[0]=v[0];
    for(int i=1;i<v.size();i++){
        waiting_time[i]=v[i]+waiting_time[i-1];
    }
    // cout<<ans[v.size()-1]<<"\n";
    for(int i=0;i<v.size();i++){
        ans+=waiting_time[i];
    }
    cout<<ans<<"\n";
}