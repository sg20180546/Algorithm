#include <iostream>
using namespace std;

int p[1001];
int r[1001];
int N;
#define INF
int cut_rod_aux(int n){

    if(r[n]>0){
        return r[n];
    }
    if(n==0){
        return 0;
    }
    int q=INT32_MIN;
    for(int i=1;i<=n;i++){
        q=max(q,p[i]+cut_rod_aux(n-i) );
    }
    r[n]=q;
    return q;
}
int cut_rod(){
    for(int i=1;i<=N;i++){
        r[i]=INT32_MIN;
    }
    int q=INT32_MIN;
    for(int i=1;i<=N;i++){
        q=max(q,cut_rod_aux(N-i)+p[i]);
    }
    return q;
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>p[i];
    }
    p[0]=0;
    cout<<cut_rod();
}