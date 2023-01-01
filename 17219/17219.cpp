#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

unordered_map<string,string> ht;
int N,K;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>K;
    string url,key;
    for(int i=0;i<N;i++){
        cin>>url>>key;
        ht.insert({url,key});
    }
    for(int i=0;i<K;i++){
        cin>>url;
        auto key=ht.find(url);
        cout<<(*key).second<<"\n";
    }
    return 0;
}