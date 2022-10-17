#include <iostream>
// #include <vector>
using namespace std;

void sol(){
    int dp[1001];
    int arr[1001];
    int N;
    cin>> N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        int score=arr[i];
        dp[i]=arr[i];
        for(int j=i+1;j<N;j++){
            score+=arr[j];
            if(score>dp[i]){
                dp[i]=score;
            }
        }
    }
    int max=INT32_MIN;
    for(int i=0;i<N;i++){
        if(dp[i]>max){
            max=dp[i];
        }
    }
    cout<<max<<"\n";
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        sol();
    }
}