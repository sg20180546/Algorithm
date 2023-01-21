#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int N,K;
deque<deque<int>> bowls;

bool Validate(){

}

void AddMinBowlOneFish(){
    vector<int> indexes;
    int min=INT32_MAX;
    for(int i=0;i<bowls.size();i++){
        if(bowls[i][0]<min){
            min=bowls[i][0];
            indexes.clear();
            indexes.push_back(i);
        }
        if(bowls[i][0]==min){
            indexes.push_back(i);
        }
    }

    for(auto i : indexes){
        bowls[i][0]++;
    }
}

void Fold1(){
    int height=bowls[0].size();
    int idx=0;
    deque<int> bowl;
    while(height<=bowls.size()-idx ){
        
        if(bowls.front().size() ){

        }

        bowl=bowls.front();
        bowls.pop_front();
        
        idx=bowl.size();
        
    }
}

void RearrangeFish(){

}

void Unfold(){

}
void Fold2(){

}


void CleanBowl(){
    AddMinBowlOneFish();
    Fold1();
    RearrangeFish();
    Unfold();
    Fold2();
    RearrangeFish();
    Unfold();
}

int main(){
    cin>>N>>K;
    int f;
    for(int i=0;i<N;i++){
        cin>>f;
        deque<int> bowl;
        bowl.push_back(f);
        bowls.push_back(bowl);
    }
    while(Validate()){
        CleanBowl();
    }
}