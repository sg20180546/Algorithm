#include <iostream>
#include <stack>
using namespace std;


void sol(){
    long long N;
    long long h;
    long long ret=0;
    stack<pair<long long,long long>> st;
    cin>>N;
    if(N==0){
        exit(0);
    }

    for(int i=0;i<N;i++){
        cin>>h;
        if(st.empty()){
            st.push({i,h});
        }
        else{
            if(h>st.top().second){
                st.push({i,h});
            }else if(h<st.top().second){
                long long tmp_x;
                while(!st.empty()&&st.top().second>h){
                    tmp_x=st.top().first; // point

                    ret=max(ret,(i-tmp_x)*st.top().second );       
                    st.pop();
                }
                st.push({tmp_x,h}); //point
            }
        }
    }
    while(!st.empty()){
        long long x=st.top().first;
        h=st.top().second;
        st.pop();
        ret=max(ret,(N-x)*h);
    }
    cout<<ret<<"\n";
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        sol();
    }
    
}

