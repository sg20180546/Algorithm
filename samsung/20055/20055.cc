#include <iostream>
#include <deque>

using namespace std;
int N,K;
int second= 1;
struct Conveyer{
    bool used;
    int lifetime ;
};

deque<Conveyer> belt;

void Rotate(){
    belt.push_front(belt.back());
    belt.pop_back();
    belt[N-1].used=false;
}

void Move(){
    for(int index=N-1;index>0;index--){

        if(belt[index].used==false && belt[index-1].used==true){
            if(belt[index].lifetime>0){
                belt[index].lifetime--;
                belt[index].used=true;
                belt[index-1].used=false;
            }
        }
        belt[N-1].used=false;

    }
}

void Put(){
    if(belt[0].lifetime>0 &&  belt[0].used==false){
        belt[0].lifetime--;
        belt[0].used=true;
    }
}

bool Check(){
    int weared=0;
    for(auto b : belt){
        if(b.lifetime==0){
            weared++;
        }
        if(weared==K){
            return false;
        }
    }
    return true;
}

int main(){
    cin>>N>>K;

    for(int i=0;i<2*N;i++){
        int l;
        cin>>l;
        belt.push_back({false,l});
    }
    while(true){
        Rotate();
        Move();
        Put();
        if(!Check()){
            break;
        }
        second++;
    }
    printf("%d\n",second);
}