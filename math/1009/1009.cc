#include <iostream>
#include <vector>
using namespace std;

int T;
typedef long long ll;
vector<int> vec[10];

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>T;
    for(int i=0;i<10;i++){
        vec[i].push_back(i);
        int tmp=i*i;
        while(tmp%10!=i){
            vec[i].push_back(tmp%10);
            tmp*=i;
        }
    }
    // for(int i=0;i<10;i++){
    //     for(auto n:vec[i]){
    //         printf("%d ",n);
    //     }
    //     printf("\n");
    // }
    int a,b;
    while(T--){
        cin>>a>>b;
        a=a%10;
        // cout<<vec[a][ (b-1)%vec[a].size() ]<<"\n";
        if(vec[a][ (b-1)%vec[a].size() ]==0){
            cout<<10<<"\n";
        }else{
            cout<<vec[a][ (b-1)%vec[a].size() ]<<"\n";
        }
    }

    return 0;
}