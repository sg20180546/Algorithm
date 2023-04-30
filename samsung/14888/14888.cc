#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

enum{
    ADD,DIFF,MUL,DIV
};

int N;
ll max_n=INT64_MIN;
ll min_n=INT64_MAX;
vector<ll> operand;
int op[4];

ll cal(int op,ll a, ll b){
    switch (op)
    {
    case ADD:
        return a+b;
        break;
    case DIFF:
        return a-b;
    case MUL:
        return a*b;
    case DIV:
        return a/b;
    default:
        break;
    }
    exit(0);
    return 0;
}

void sol(int idx,ll res){
    if(idx==N-1){
        if(res>max_n){
            max_n=res;
        }
        if(res<min_n){
            min_n=res;
        }
        return;
    }

    for(int i=0;i<4;i++){
        if(op[i]>0){
            op[i]--;
            sol(idx+1,cal(i,res, operand[idx+1] ));
            op[i]++;
        }
    }
}

int main(){
    cin>>N;
    operand.assign(N,0);
    for(int i=0;i<N;i++){
        cin>>operand[i];
    }

    for(int i=0;i<4;i++){
        cin>>op[i];
    }

    for(int i=0;i<4;i++){
        if(op[i]>0){
            op[i]--;
            sol(1,cal(i,operand[0],operand[1]));
            op[i]++;
        }
    }
    printf("%lld\n%lld\n",max_n,min_n);
    return 0;
}