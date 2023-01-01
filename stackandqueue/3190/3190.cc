#include <iostream>

#include <deque>
#include <queue>
#include <memory.h>
using namespace std;
queue<pair<int,char>> q;
deque<pair<int,int>> snake;
int N,K,L;

int ans;

char board[104][104];
// R D L U
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};

bool check(int y,int x){
    return y>=1&&y<=N&&x>=1&&x<=N;
}

int main(){
    cin>>N>>K;
    int y, x;
    ans=0;
    memset(board,0,sizeof(board));
    while(K--){
        cin>>y>>x;
        board[y][x]='a';
    }
    cin>>L;
    int t;
    char d;
    while(L--){
        cin>>t>>d;
        q.push({t,d});
    }
    int dir;
    dir=0;
    snake.push_back({1,1});
    board[1][1]='s';

    while(1){
        ans++;
        int y=snake.front().first;
        int x=snake.front().second;
        // printf("%d %d %d\n",y,x,dir);
        y+=dy[dir];
        x+=dx[dir];
        

        if(!check(y,x)){
            break;
        }
        
        if(board[y][x]=='s'){
            break;
        }

        if(board[y][x]!='a'){
            int taily=snake.back().first;
            int tailx=snake.back().second;
            snake.pop_back();
            board[taily][tailx]=0;
        }

        board[y][x]='s';
        snake.push_front({y,x});

        if(q.front().first==ans){
            if(q.front().second=='L'){
                dir--;
               dir = dir < 0 ? dir=3:dir;
            }else{
                dir=(dir+1)%4;
            }
            q.pop();
        }

    }

    cout<<ans<<"\n";
}