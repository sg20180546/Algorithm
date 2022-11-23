#include <iostream>
#include <stack>
using namespace std;
// 6549
int N;

typedef struct labor{
    int day;
    int wage;
}labor;
stack<labor> s;

int main(){
    cin>>N;
    int w;
    int ans=INT32_MIN;
    int day_tmp;
    for(int d=0;d<N;d++){
        cin>>w;
        if(s.empty()) s.push({d,w});
        else{

            if(s.top().wage<w){
                s.push({d,w});
            }else if(s.top().wage>w){
                while(!s.empty()&&s.top().wage>w){
                    day_tmp=s.top().day;
                    int total=s.top().wage*(d-day_tmp );
                    s.pop();
                    if(total>ans){
                        ans=total;
                    }
                }
                s.push({day_tmp,w});
            }

        }
    }

    while(!s.empty()){
        w=s.top().wage;
        day_tmp=s.top().day;
        s.pop();
        int total=w*(N-day_tmp);
        if(total>ans){
            ans=total;
        }
    }
    printf("%d\n",ans);
}
