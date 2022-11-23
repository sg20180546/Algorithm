#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long N;
vector<pair<long,long>> meeting;


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N;
    long start,end;
    for(int i=0;i<N;i++){
        cin>>start>>end;
        meeting.emplace_back(end,start);
    }
    sort(meeting.begin(),meeting.end());

    end=meeting[0].first;
    int ans=1;
    for(int i=1;i<N;i++){
        if(meeting[i].second>=end){
            ans++;
            end=meeting[i].first;
        }
    }
    cout<<ans<<"\n";
}