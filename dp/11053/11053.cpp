#include <iostream>

using namespace std;
// O(N^2)
int lis[1001];

int l[1001];
int N;

int LIS(){
    for(int i=N-1;i>=0;i--){
        int m=1;
        for(int j=i+1;j<N;j++){
            if(l[i]<l[j]){
                if(m<lis[j]+1 ){
                    m=lis[j]+1;
                }
            }
        }
        lis[i]=m;
    }
    int ret=0;
    for(int i=0;i<N;i++){
        if(ret<lis[i]){
            ret=lis[i];
        }
    }
    return ret;
}

int main(){
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>l[i];
    }
    cout<<LIS();
}