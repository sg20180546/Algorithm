#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// time over
int N;

int cumsum_and_diff(vector <pair<int,int>>& vec,int* index){
    int max_diff=INT32_MIN;
    int cumsum=0;
    
    for(int i=0;i<N;i++){
        cumsum+=vec[i].second;
        int diff=cumsum-vec[i].first;
    }

    return max_diff;
}


void sol(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int time;
    int due;
    int index;
    cin>>N;
    vector <pair<int,int>> v;
    vector <int> late;
    queue<int> time_tmp;
    queue<int> due_tmp;
    for(int i=0;i<N;i++){
        cin>>time;
        time_tmp.push(time);
    }
    for(int i=0;i<N;i++){
        cin>>due;
        due_tmp.push(due);
    }
    for(int i=0;i<N;i++){
        // time=time_tmp.front();
        v.emplace_back(due_tmp.front(),time_tmp.front());
        time_tmp.pop(); due_tmp.pop();
    }
    sort(v.begin(),v.end());
    int cumsum=0;
    for(int i=0;i<N;i++){
        cumsum+=v[i].second;
        int diff=max(cumsum-v[i].first,0);
        // cout<<"diff : "<<diff<<"\n";
        late.push_back(diff);
    }
    int ans=INT32_MAX;
    for(int i=1;i<N;i++){
        auto front=*max_element(late.begin(),late.begin()+i-1);
        auto rear=*(max_element(late.begin()+i,late.end())) - v[i].second+1;
        int tmp=max(front,rear);
        ans=min(tmp,ans);
    }
    printf("%d\n",ans);
}




int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        sol();
    }
}
