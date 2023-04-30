#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> A;
// vector<pair<int,int>> B;
vector<int> B;

int main(){
    cin>>N;
    int n;
    for(int i=0;i<N;i++){
        cin>>n;
        A.push_back(n);
    }

    for(int i=0;i<N;i++){
        cin>>n;
        B.push_back(n);
    }
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    int ans=0;
    for(int i=0;i<N;i++){
        // printf("%d %d\n",A[i],B[i]);
        ans+=A[i]*B[i];
    }
    cout<<ans<<"\n";

}