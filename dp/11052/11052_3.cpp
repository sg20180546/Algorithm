#include <iostream>
using namespace std;
int r[1001];
int p[1001];
int c[1001];

int N;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>p[i];
    }
    p[0]=0;
    for(int i=1;i<=N;i++){
        int q=INT32_MIN;
        for(int j=1;j<=i;j++){
            if(q<p[j]+r[i-j] ){
                q=p[j]+r[i-j] ;
                c[i]=j;
            }
        }
        r[i]=q;
    }
    cout<<r[N];
}
