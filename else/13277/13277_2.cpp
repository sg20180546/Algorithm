#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include <algorithm>
// https://m.blog.naver.com/dlscjs8646/222209735766
using namespace std;

const double PI= acos(-1);

typedef complex<double> cpx;

void FFT(vector<cpx>& f, cpx w){
    
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){

}

void getn(vector<cpx>& complex){
    while(1){
        char c=getchar();
        if(c==' '){
            break;
        }
        complex.push_back(cpx(c-'0'));
    }
}

int main(){
    vector<cpx> x,y,z;

    getn(x);
    getn(y);

    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    z=multiply(x,y);

    int len=z.size();
    int carry=0;
    vector<int> ans;

    for(int i=0;i<len;i++){
        int n=(int)round(z[i].real())+carry;
        carry=n/10;
        ans.push_back(n%10);
    }
    while(carry>0){
        ans.push_back(carry%10);
        carry/=10;
    }
    int i=ans.size()-1;
    for(;i>=0;i--){
        if(ans[i]!=0){
            break;
        }
    }
    if(i<0){
        cout<<"0";
    }
    else{
        for(;i>=0;i--){
            cout<<ans[i];
        }
    }
    return 0;
}