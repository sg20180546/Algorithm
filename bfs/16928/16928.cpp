#include <iostream>
#include <queue>


using namespace std;

queue<std::pair<int,int>> q; // pos,move


int map[102][2];
bool moved[102];


int bfs(){
    q.push({1,0});
    // printf("bfs\n");
    while(!q.empty()){
        int pos=q.front().first;
        int move=q.front().second;
        q.pop();

        // printf("%d %d\n",pos,move);
        if(pos>=100){
            return move;
        }
        if(moved[pos]==true){
            continue;
        }        
        moved[pos]=true;
        if(map[pos][0]==1){
            pos=map[pos][1];
        }
        for(int i=1;i<=6;i++){
            q.push({pos+i,move+1});
        }
    }
    return -1;
}


int main(){
    int ladder,snake;
    int start,dest;
    cin>>ladder>>snake;
    for(int i=0;i<102;i++){
        map[102][2]=0;
        moved[i]=false;
    }
    for(int i=0;i<ladder+snake;i++){
        cin>>start>>dest;
        map[start][0]=1;
        map[start][1]=dest;
    }

    cout<<bfs()<<"\n";
}