#include <iostream>
using namespace std;



void sol(int find, int k, int len){
    int new_len=len*2+k+3;
    if(find<=3){
        if(find==1){
            printf("m\n");
        }else{
            printf("o\n");
        }
        exit(0);
    }
    if(find>new_len){
        sol(find,k+1,new_len);
    }
    if(find>len && find <=len+k+3){
        if(find-len==1){
            printf("m\n");

        }else{
            printf("o\n");
        }
        exit(0);
    }
    
    sol(find-len-k-3,1,3);
}


int main(){
    int N;
    cin>>N;
    sol(N,1,3);
}