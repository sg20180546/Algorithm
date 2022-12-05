#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N,E,B;

bool connected[1001];
vector<pair<int,int>> blue;
vector<pair<int,int>> red;

bool check(){
    for(int i=1;i<=N;i++){
        if(connected[i]==false){
            return false;
        }
    }
    return true;
}
void sol(){
    char type;
    int a,b;

    blue.clear();
    red.clear();
    cin>>N>>E>>B;
    if(N==0&&E==0&&B==0){
        exit(0);
    }
    for(int i=0;i<E;i++){
        cin>>type;
        cin>>a>>b;
        if(type=='R'){
            red.emplace_back(a,b);
        }else{
            blue.emplace_back(a,b);
        }
    }
    int bsize=blue.size();
    int rsize=red.size();
    // int loop=bsize;
    // if(B==0){
    //     loop=rsize;
    // }
    for(int i=0;i<E;i++){
        memset(connected,false,sizeof connected);  
        int n_blue=0;
        if(i>=bsize){
            connected[red[i-bsize].first]=true;
            connected[red[i-bsize].second]=true;
        }else{
            connected[blue[i].first]=true;
            connected[blue[i].second]=true;
            n_blue++;
        }

        
        while(1){
            bool connected_cmp[1001];
            bool changed=false;
            memcpy(connected_cmp,connected,sizeof connected);
            // if(n_blue!=B){
                for(int j=0;j<bsize&&n_blue<B ;j++){
                    if(connected[blue[j].first]&&connected[blue[j].second]){
                        continue;
                    }
                    if(!connected[blue[j].first]&&!connected[blue[j].second]){
                        continue;
                    }
                    if(connected[blue[j].first] && !connected[blue[j].second]){
                        // printf(" 1 : %d %d \n",blue[j].first,blue[j].second);
                        connected[blue[j].second]=true;
                        n_blue++;
                        // break;
                    }
                    if(!connected[blue[j].first]&& connected[blue[j].second]){
                                                // printf(" 2 : %d %d \n",blue[j].first,blue[j].second);

                        connected[blue[j].first]=true;
                        n_blue++;
                        // break;
                    }
                }
            // }
            for(int j=0;j<rsize;j++){
                if(connected[red[j].first]&&connected[red[j].second]){
                    continue;
                }
                if(!connected[red[j].first]&&!connected[red[j].second]){
                    continue;
                }
                if(connected[red[j].first] && !connected[red[j].second]){
                    connected[red[j].second]=true;
                    break;
                }
            if(!connected[red[j].first]&& connected[red[j].second]){
                    connected[red[j].first]=true;
                    break;
                }
            }
        
        if(!memcmp(connected_cmp,connected,sizeof connected)){
            break;
        }

        if(check()&&n_blue==B){
            cout<<"1\n";
            return;
        }

        }

    }
    cout<<"0\n";
    // vector
}

int main(){
    cin.tie(); cout.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        sol();
    }
}