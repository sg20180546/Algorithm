#include <iostream>

using namespace std;

// 3
// 3 + (m) + (o*(1+2)) + 3 = 10
// 10 + (m) +  + 10 = 25 // 

// L(k) = L(k-1)*2 + (k+3)
// 11

// k=11
// 25
// at middle 10(Sn-1) < k < 15
// k=11 m, else o

// k=5
// at left
// 25
// k<10(Sn-1)
// at middle 3(Sn-2) < k < 7
// k=6 m, else o

// k=21
// k>15 at right
// 15+3<k<25-3
// if k=19 m, else 0

// void len(int l,int k,int i,int prev){
    
//     int r=l*2+(i+3);
//     if(k<=prev){ // left
//         len(prev,k,i-1,);
//     }
    
//     if(k>r-prev){ //right
//         len(r,k,i+1,l);
//     }
//     if(k>prev && k<=r-prev){ //middle
//         if(k=prev+1){
//             cout<<"m\n";
//             return;
//         }else{
//             cout<<"o\n";
//         }
//     }

    
//     return;
// }
// char s1[3]={'m','o','o'};
// void len(int n, int k, int l){
//     int new_l=l*2+k+3;
//     if(n<=3){
//         cout<<s1[n-1];
//     }
//     if(new_l<n){
//         len(n,k+1,new_l);
//     }else{
//         if(n>l&&n<=l+k+3){
//             if(n-l!=1){
//                 cout<<"o";
//             }else{
//                 cout<<"m";
//             }
//             exit(0);
//         }else{
//             len(n-(l+k+3),1,3);
//         }
//     }
// }

// int main(){
//     int k;
//     cin>>k;
//     len(k,1,3);
// }

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

char s1[3] = {'m', 'o','o'};

void sol(int n, int k, int len){
    int new_len = len*2 + k+3;
    if(n<=3){
        printf("%c\n", s1[n-1]);
        exit(0);
    }
    if(new_len < n){ // over the len
        sol(n, k+1, new_len);
    }
    else{
        if(n > len && n <= len+k+3){ // middle
            if(n-len == 1)
                printf("m\n");
            else
                printf("o\n");
            exit(0);
        }
        else{ // n <= len || n>len+k+3
            sol(n-(len+k+3), 1, 3);
        }
    }
}

int main(void){
    int n;
   
    scanf("%d", &n);
    
    sol(n, 1, 3);
    
}