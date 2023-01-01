#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
set<int> s;
int heights[25002];
ll sum=0;
int n;
int main(){
    cin>>n;
    while(n--){
        int value;
        cin>>value;
        auto iter = s.lower_bound(value);
        ll left,right;
        if(iter!=s.begin()){
            auto left_iter=iter;
            left=heights[*(--left_iter)];
        }else{
            left=0;
        }

        if(iter!=s.end()){
            right=heights[(*iter)];
        }else{
            right=0;
        }
        heights[value]=max(left,right)+1;
        s.insert(value);
        sum+=heights[value];
    }

    cout<<sum;
}