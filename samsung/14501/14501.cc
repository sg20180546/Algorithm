#include <iostream>
#include <vector>
using namespace std;
int dp[20];
int N;
vector<pair<int,int>> counsel;

int main(){
    cin>>N;
    counsel.emplace_back(-1,-1);
    for(int i=0;i<N;i++){
        int T,P;
        cin>>T>>P;
        counsel.emplace_back(T,P);
    }
    for(int day=N;day>=1;day--){
        int end_day=day+counsel[day].first-1;
        int pay=counsel[day].second;
        if(end_day>N){
            continue;
        }
        
        int tmp=0;
        end_day++;
        for(;end_day<=N;end_day++){
            if(dp[end_day]>tmp){
                tmp=dp[end_day];
            }
        }
        dp[day]=tmp+pay;

    }
    int ans=0;
    for(int i=1;i<=N;i++){
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    cout<<ans<<"\n";
}