#include <iostream>
#include <stack>
#include <string>

using namespace std;
deque <char> dq;

int N,K;
string s;
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>K;
    cin>>s;
    for(int i=0;i<N;i++){

            while(K>0&&!dq.empty()&&s[i]>dq.back()){
                dq.pop_back();
                K--;
            }
            dq.push_back(s[i]);
        
    }

    for(int i=0;i<dq.size()-K;i++){
        cout<<dq[i];
    }
    cout<<"\n";

    return 0;
}