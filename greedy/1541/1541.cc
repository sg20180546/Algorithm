#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int ans=0;
string src;


int main(){
    cin>>src;
    bool after_minus=false;
    string n;
    for(auto c: src ){
        if(c=='+' || c=='-' ){
            if(after_minus){
                ans-=stoi(n);
            }else{
                ans+=stoi(n);
            }
            n.clear();
        }else{
            n+=c;
        }
        if(c=='-'){
            after_minus=true;
        }
    }
    if(after_minus){
        ans-=stoi(n);
    }else{
        ans+=stoi(n);
    }
    cout<<ans<<"\n";
}