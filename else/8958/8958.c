#include <stdio.h>
#include <string.h>
int N,i,j;

int cumsum(int x){
    // 4 4+3+2+!
    // 5 5+4+3+2+
    int ret=0;
    while(x){
        ret+=x;
        x--;
    }
    return ret;
}

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        int score=0;
        char str[80];
        scanf("%s",str);
        int len=strlen(str);

        for(j=0;j<len;j++){ // 0 4 5 7
            int dx=0;
            // OOOOXOOXOOOXXX
            while(str[j]=='O'){
                dx++; j++; // 4 4 
            }
            score+=cumsum(dx);
        }


        printf("%d\n",score);
    }
}

