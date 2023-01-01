#include <iostream>
int arr[10005];
using namespace std;

void post(int start,int end){
    // printf("%d %d\n",start,end);
    if(start>=end){
        return;
    }

    int i;
    for(i=start+1;i<end;i++){
        if(arr[start]<arr[i]){
            break;
        }
    }
    post(start+1,i);
    post(i,end);
    printf("%d\n",arr[start]);
}


int main(){
    int n=0;
    int num;
    while(cin>>arr[n]) {
        // arr[n++]=num;
        n++;
    }
    post(0,n);
    return 0;
}