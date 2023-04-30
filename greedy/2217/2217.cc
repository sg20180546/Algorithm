#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;

int main(){
    cin>>N;
    int w;
    while(N--){
        cin>>w;
        v.push_back(w);
    }
    sort(v.rbegin(),v.rend());

    int i=0;
    int ans_i=0;
    int min_w=0;

    for(auto w : v){
        // cout<<"w : "<<w<<"\n";
        if(ans_i*min_w<(i+1)*w ){
            min_w=w;
            ans_i=i+1;
        }
        i++;
    }
    cout<<ans_i*min_w<<"\n";
}