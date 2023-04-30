#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#define LINEAR_INDEX(R,i,j) (R)*(i)+(j)

using namespace std;
int N,K;
deque<deque<int>> bowls;

int ans=0;
void Print(){
    for(auto b: bowls){
        for(auto f : b){
            printf("%d ",f);
        }
        printf("\n");
    }
    printf("\n\n");
}

bool Validate(){
    int max_f=INT32_MIN;
    int min_f=INT32_MAX;
    for(auto b :bowls){
        if(b[0]>max_f){
            max_f=b[0];
        }
        if(b[0]<min_f){
            min_f=b[0];
        }
    }
    if(abs(max_f-min_f)<=K)
        return true;
    else
        return false;
}

void AddMinBowlOneFish(){
    vector<int> indexes;
    int min=INT32_MAX;
    for(int i=0;i<bowls.size();i++){
        if(bowls[i][0]<min){
            min=bowls[i][0];
            indexes.clear();
            indexes.push_back(i);
            continue;
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
    while(1){
        for(int i=1;i<bowls.size();i++){
            if(bowls[i].size()==1){
                idx=i;
                break;
            }
        }

        if(bowls.front().size() > bowls.size()-idx ){
            return;
        }

        for(int i=idx-1;i>=0;i--){
            bowl=bowls[i];
            for(int j=idx,f=0;f<bowl.size();j++,f++){
                bowls[j].push_back(bowl[f]);
            }
        }
        
        for(int i=0;i<idx;i++){
            bowls.pop_front();
        }
    }
}

int di[]={0,0,-1,1};
int dj[]={1,-1,0,0};

struct passinfo{
    int fromy;
    int fromx;
    int toy;
    int tox;
    int n;
};

void RearrangeFish(){
    vector<passinfo> pass;
    bool check[200][200];
    memset(check,false,sizeof(check));
    int R=bowls[0].size();
    for(int i=0;i<bowls.size();i++){
        for(int j=0;j<bowls[i].size();j++){
            for(int k=0;k<4;k++){
                int ni=i+di[k];
                int nj=j+dj[k];
                if(ni<bowls.size()&&ni>=0&&nj<bowls[ni].size()&&nj>=0 )
                {
                    int cur=bowls[i][j];
                    int compare=bowls[ni][nj];

                    int cur_i=LINEAR_INDEX(R,i,j);
                    int compare_i=LINEAR_INDEX(R,ni,nj);

                    if(check[cur_i][compare_i]==true){
                        continue;
                    }
                    check[cur_i][compare_i]=true;
                    check[compare_i][cur_i]=true;
                    int diff=cur-compare;
                    if(diff>0){
                        pass.push_back({i,j,ni,nj,abs(diff)/5});
                    }else if(diff<0){
                        pass.push_back({ni,nj,i,j,abs(diff)/5});
                    }
                }
            }
        }
    }

    for(auto p : pass){
        bowls[p.fromy][p.fromx]-=p.n;
        bowls[p.toy][p.tox]+=p.n;
    }
}

void Unfold(){
    vector<deque<int>> tmp;
    for(auto bowl : bowls){
        if(bowl.size()==1){
            break;
        }
        for(auto f : bowl){
            deque<int> b;
            b.push_front(f);
            tmp.push_back(b);
        }
        bowls.pop_front();
    }
    for(auto it=tmp.rbegin();it!=tmp.rend();it++){
        bowls.push_front(*it);
    }

}
void Fold2(){
/*
0->7
1->6
2->5
3->4
*/
    for(int j=0;j<2;j++)
    {    
        int bowls_n=bowls.size();
        for(int i=0;i<(bowls_n)/2;i++ ){
            for(auto it=bowls[i].rbegin();it!=bowls[i].rend();it++)
            bowls[bowls_n-i-1].push_back(*it);
        }

        for(int i=0;i<(bowls_n)/2;i++){
            bowls.pop_front();
        }
    }

}


void CleanBowl(){
    AddMinBowlOneFish();
    Fold1();
    // Print();
    RearrangeFish();
    // Print();
    Unfold();
    // Print();
    Fold2();
    // Print();
    RearrangeFish();
    // Print();
    Unfold();
    // Print();
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

    while(!Validate()){
        ans++;
        CleanBowl();
    }
    cout<<ans<<"\n";
}