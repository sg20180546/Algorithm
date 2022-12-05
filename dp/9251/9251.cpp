#include <string>
#include <iostream>

using namespace std;
string X,Y;
#define max(a,b) (a)>(b) ? (a) : (b)
int c[1001][1001];

int LCS(){
    size_t n=X.length();
    size_t m=Y.length();

    for(int i=0;i<=n;i++){
        c[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        c[0][j]=0;
    }
    c[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=1+c[i-1][j-1];
            }else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    return c[n][m];
}

int main(){
    cin>>X>>Y;
    // cout<<"ans"<<LCS()<<"\n";
    
    // for(int i=0;i<=X.length();i++){
    //     for(int j=0;j<=Y.length();j++){
    //         printf("%d ",c[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("%d %d",X.length(),Y.length());
    cout<<LCS();
}