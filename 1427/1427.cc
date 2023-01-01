#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string src;
vector<int> ans;

int main(){
    cin>>src;
    for(int i=0;i<src.length();i++){
        ans.push_back(src[i]-'0' );
    }
    sort(ans.begin(),ans.end());

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
}