#include <iostream>
#include <string>
#include <cmath>
#include <stdint.h>
#include <vector>
#include <deque>
#include <assert.h>
#include <unistd.h>
using namespace std;

typedef deque<int8_t> number;

void print(number& vec){
    size_t size=vec.size();
    for(int i=size-1;i>=0;i--){
        printf("%d",vec[i]);
    }
    printf("\n");
}

void normalize(string src,number& dst){
    int len=src.length();
    for(int i=len-1;i>=0;i--){
        dst.push_back(src[i]-'0');
    }
}

number add(number a,number b){
    int asize=a.size();
    int bsize=b.size();
    number ret;
    if(asize==1&&bsize==1){
        // assert(a[0]<)
        int retn=a[0]*b[0];
        ret.push_back(retn%10);
        ret.push_back(retn/10);
        return ret;
    }
   int i;


    if(asize>bsize){
        for(i=0;i<bsize;i++){
            ret.push_back(a[i]+b[i]);
        }
        for(;i<asize;i++){
            ret.push_back(a[i]);
        }
    }else{
        for(i=0;i<asize;i++){
            ret.push_back(a[i]+b[i]);
        }
        for(;i<bsize;i++){
            ret.push_back(b[i]);
        }
    }
// 1 10 100 1000
    asize=ret.size();
    for(i=0;i<asize-1;i++){
        assert(ret[i]<20);
        if(ret[i]>=10){
            ret[i]-=10;
            ret[i+1]+=1;
        }
    }
    if(ret[asize-1]>=10){
        ret[asize-1]-=10;
        ret.push_back(1);
    }
    return ret;
}

bool is_there_negative(number& v,size_t size){
    for(int i=0;i<size;i++){
        if(v[i]<0){
            return true;
        }
    }
    return false;
}

number sub(number& a,number& b){

    int asize=a.size();
    int bsize=b.size();
    number ret(asize,0);
    int i;

    for(i=asize-1;i>=bsize;i--){
        ret[i]=a[i];
    }
    for(;i>=0;i--){
        ret[i]=a[i]-b[i];
    }
    // printf("2\n");

    // printf("2.5\n");

    while(is_there_negative(ret,asize-1)){
        for(i=asize-1;i>=0;i--){
            if(ret[i]<0){
                ret[i+1]-=1;
                ret[i]+=10;
            }
        }
    }
        // printf("3\n");
    for(i=asize-1;i>=0;i--){
        if(ret[i]>0){
            break;
        }
        ret.pop_back();
    }
    return ret;
}

void divide_number(number& src,number& a1,number& a0,int pos){
    int size=src.size();
    int i;
    for(i=0;i<pos;i++){
        a0.push_back((src)[i]);
    }
    for(;i<size;i++){
        a1.push_back((src)[i]);
    }

}

int denormalize(number& A){
    int size=A.size();
    int ret=0;
    for(int i=0;i<size;i++){
        ret+=A[i]*pow(10,i);
    }
    return ret;
}

number karatsuba(number& A,number& B){
    int power=B.size()-1;
    int asize=A.size()-1;
    // sleep(1);
    // printf("at first:\n");
    // print(A); print(B);
    number res;
    int i;
    if(power<=1||asize<=1){
        int mul=denormalize(A)*denormalize(B);

        normalize(to_string(mul),res);
        return res;
    }

    if(power>asize){
        number tmp=A;
        A=B;
        B=tmp;
        power=asize;
    }
    number a1;
    number a0;
    // printf("Devide by %d\n",power);
    divide_number(A,a1,a0,power);
    number b1;
    number b0;
    // print(a1); print(a0);

    divide_number(B,b1,b0,power);
    // print(b1); print(b0);
    number z2=karatsuba(a1,b1);
    number z0=karatsuba(a0,b0);
    number a1a0=add(a1,a0);
    number b1b0=add(b1,b0);
    number z1=karatsuba(a1a0,b1b0);
    z1=sub(z1,z0);
    z1=sub(z1,z2);

    for(i=0;i<power;i++){
        z2.push_front(0);
        z1.push_front(0);
    }
    for(i=0;i<power;i++){
        z2.push_front(0);
    }
    res=add(z2,z1);
    res=add(res,z0);
    return res;
}

int main(){
    string A,B;
    cin>>A>>B;
    number nA,nB,result;
    normalize(A,nA);
    normalize(B,nB);

    result=karatsuba(nA,nB);

    print(result);
}