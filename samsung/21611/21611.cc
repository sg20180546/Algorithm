#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
/*

48 47 46 45 44 43 42
25 24 23 22 21 20 41
26  9  8  7  6 19 40
27 10  1  0  5 18 39
28 11  2  3  4 17 38
29 12 13 14 15 16 37
30 31 32 33 34 35 36

*/

struct Cell{
    int num;
    int index;
};


enum{
    NONE,UP,DOWN,LEFT,RIGHT
};
int dy[5]={0,-1,1,0,0};
int dx[5]={0,0,0,-1,1};
int N,M;
Cell map[51][51];
int score = 0;
std::vector<pair<int,int>> magic;
deque<int > dq;

bool check(int y,int x){
    return y>=0&&y<N&&x>=0&&x<N;
}


void PrintIndex(){
    for(int i = 0; i< N;i++){
        for(int j=0;j<N;j++){
            printf("%4d ",map[i][j].index);
        }
        printf("\n");
    }
}
void PrintDq(){
    // printf("\n");
    // for(auto e : dq){
    //     printf("%d ",e);
    // }
    // printf("size :%ld\n",dq.size());
}

/*
3->1
5->2
7->3
*/
void ParseToDQ(){


    // right,down,left,up
    int dir = RIGHT;
    int y=0;
    int x=0;
    int index = N*N-1;
    while(true){
        if(y==(N+1)/2 -1&& x==(N+1)/2 -1 ){
            dq.push_back(0);
            break;
        }
        if(map[y][x].num != 0){
            dq.push_back(map[y][x].num);
        }

        map[y][x].num=-1;
        map[y][x].index=index--;

        int ny=y+dy[dir];
        int nx=x+dx[dir];
        if(check(ny,nx) && map[ny][nx].num!=-1){
            y=ny;
            x=nx;
            continue;
        }
        switch (dir)
        {
        case LEFT:
            dir=UP;
            break;
        case DOWN:
            dir=LEFT;
            break;
        case UP:
            dir=RIGHT;
            break;
        case RIGHT:
            dir=DOWN;
            break; 
        default:
            break;
        }
        y+=dy[dir];
        x+=dx[dir];
    }
    reverse(dq.begin(),dq.end());
}
void Pull(){
    vector<int> tmp;
    tmp.clear();
    for(int j= 0;j<dq.size();j++){
        if(dq[j]!=-1){
            tmp.push_back(dq[j]);
        }
    }
    dq.clear();
    for(int j=0;j<tmp.size();j++){
        dq.push_back(tmp[j]);
    }
}


void Explode(){
    bool exploded;
    if(dq.size()==1){
        return;
    }
    do
    {   
        exploded=false;
        int start, end;
        for(start=1;start<dq.size();start=end){
            if(dq[start]==0){
                break;
            }
            for(end=start+1;end<dq.size() &&dq[start]==dq[end];){
                end++;
            }
            
            if(end-start>=4){
                score+=(end-start)*dq[start];
                // dq.erase(dq.begin()+start,dq.begin()+end);
                for(int i = start;i<end;i++){
                    dq[i]=-1;
                }
                exploded=true;
                // break;
            }
        }   
        Pull();

    }while (exploded==true);
    
}

void Rearrange(){
    if(dq.size()==1){
        return;
    }
    vector<int> tmp;
    tmp.clear();
    int start,end;
    for(start=1;start<dq.size();start=end){

        for(end=start+1;end<dq.size() &&dq[end]==dq[start];){
            end++;
        }
        if(end-start>0){ 
            tmp.push_back(end-start);
            tmp.push_back(dq[start]);
        }
    }
    dq.clear();
    dq.push_front(0);
    for(int i=0;i<tmp.size() &&i<N*N-1;i++){
        dq.push_back(tmp[i]);
    }
    
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int n;
            cin>>n;
            map[i][j].num=n;
        }
    }


    ParseToDQ();

    for(int i=0;i<M;i++){
        int dir,dis;
        cin>>dir>>dis;
        magic.push_back({dir,dis});
    }

    PrintDq();
    for(auto m : magic){

        int x=(N+1)/2-1;
        int y=(N+1)/2-1;
        vector<int> tmp;
        tmp .clear();
        for(int i=0;i<m.second;i++){

            int nx=x+dx[m.first];
            int ny=y+dy[m.first];
 
            if(!check(ny,nx)){
                
                break;
            }
            if(dq.size()>map[ny][nx].index){
                dq[map[ny][nx].index]=-1;
            }
            y=ny;
            x=nx;   
        }
        for(int j= 0;j<dq.size();j++){
            if(dq[j]!=-1){
                tmp.push_back(dq[j]);
            }
        }
        dq.clear();
        for(int j=0;j<tmp.size();j++){
            dq.push_back(tmp[j]);
        }

        Explode();
        Rearrange();
    }
    // PrintDq();
    cout<<score<<"\n";
}