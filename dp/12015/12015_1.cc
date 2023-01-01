#include <iostream>
#include <vector>
using namespace std;
int N;
int l[1000001];
vector<int> seq;

void binary_search(int num){
    int index=INT32_MAX;
    int low=0;
    int high=seq.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(seq[mid]>=num ){
            if(index>mid){
                index=mid;
            }
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    seq[index]=num;
}

void LIS(){
    seq.push_back(l[0]);
    for(int i=1;i<N;i++){
        if(seq.back()<l[i]){
            seq.push_back(l[i]);
        }else{
            binary_search(l[i]);
        }
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>l[i];
    }
    LIS();
    cout<<seq.size();
}