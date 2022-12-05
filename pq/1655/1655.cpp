#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N;
priority_queue< int , vector<int> ,less<int>> max_pq; //  9 5 4 3 1 -1
priority_queue< int , vector<int> ,greater<int>> min_pq; // 11 15 12 17 18 19

int main(){
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin>>n;
        if(max_pq.size()<=min_pq.size()){
            max_pq.push(n);
        }else{
            min_pq.push(n);
        }
        if(min_pq.empty()==false&&max_pq.empty()==false){
            if(( min_pq.top()<max_pq.top())){
                int minele=min_pq.top();
                int maxele=max_pq.top();
                max_pq.pop(); min_pq.pop();
                max_pq.push(minele); min_pq.push(maxele);
            }

        }
        cout<<max_pq.top()<<"\n";
    }
    
}