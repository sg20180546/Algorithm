#include <stack>
#include <iostream>
using namespace std;
int n;
int w;
int tmp_i;
long long ans=0,tmp;
typedef struct labor{
    int day;
    int w;
    labor(int d,int w) : day(d),w(w) {}
}labor;
stack<labor> s;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w;
        if(s.empty()) s.emplace(i,w);
        else{
            if(s.top().w<w){
                s.emplace(i,w);
            }else if(s.top().w>w){
                while(!s.empty()&&s.top().w>w){
                    tmp=s.top().w*(i-s.top().day);
                    tmp_i=s.top().day;
                    s.pop();
                    if(tmp>ans){
                        ans=tmp;
                    }
                }
                s.emplace(tmp_i,w);
            }
            printf("ans[%d] : %d\n",i,ans);
        }
    }
    while(!s.empty()){
        tmp=s.top().w*(n-s.top().day);
        s.pop();
        if(tmp>ans) ans=tmp;
    }
    printf("%d\n",ans);
}